// -*- compile-command: "gcc -o problem_054 problem_054.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *nameFile;

typedef struct card card;
typedef struct hand hand;
typedef struct deal deal;

struct card
{
    int suit;
    int value;
};

struct hand
{
    card cards[5];
};

struct deal
{
    hand player[2];
};

bool isFlush(hand player)
{
    int i;
    for (i = 1; i<5; i++)
        if (player.cards[i].suit != player.cards[0].suit)
            return false;
    return true;
}

int highCard(hand player)
{
    int i, max=0;
    for (i = 0; i<5; i++)
        if (player.cards[i].value > max) max = player.cards[i].value;
    return max;
}

int isStraight(hand player)
{
    int min=15, i;
    for (i = 0; i<5; i++)
        if (player.cards[i].value < min) min = player.cards[i].value;

    int max=0;
    for (i = 0; i<5; i++)
        if (player.cards[i].value > max) max = player.cards[i].value;

    if ((max - min) != 4) return 0;

    int visited[5] = {0};
    for (i = 0; i<5; i++)
        if (visited[player.cards[i].value - min] > 0 )
            return 0;
        else
            visited[player.cards[i].value - min] ++;

    return max;
}

int isPair(hand player)
{
    int i;
    int visited[16] = {0};
    for (i = 0; i<5; i++)
        visited[player.cards[i].value] ++;

    for (i = 0; i<16; i++)
        if (visited[i] == 2)
            return i;
    return 0;
}

int isTwoPair(hand player)
{
    int i;
    int visited[16] = {0};
    for (i = 0; i<5; i++)
        visited[player.cards[i].value] ++;

    int count=0;
    for (i = 0; i<16; i++)
        if (visited[i] == 2)
        {
            if (count == 1)
                return i;
            else
                count++;
        }
    return 0;
}

int isThree(hand player)
{
    int i;
    int visited[16] = {0};
    for (i = 0; i<5; i++)
        visited[player.cards[i].value] ++;

    for (i = 0; i<16; i++)
        if (visited[i] == 3)
            return i;
    return 0;
}

int isFour(hand player)
{
    int i;
    int visited[16] = {0};
    for (i = 0; i<5; i++)
        visited[player.cards[i].value] ++;

    for (i = 0; i<16; i++)
        if (visited[i] == 4)
            return i;
    return 0;
}

unsigned long long handScore(hand player)
{
    int DEBUG = 0;

    if (DEBUG == 1)
    {
        //Debug Print
        int cardIndex=0;
        for (cardIndex = 0; cardIndex<5; cardIndex++)
        {
            printf("(%d)%d, ",
                   player.cards[cardIndex].suit,
                   player.cards[cardIndex].value);
        }
        printf("\n");
    }

/*
    High Card: Highest value card.
    One Pair: Two cards of the same value.
    Two Pairs: Two different pairs.
    Three of a Kind: Three cards of the same value.
    Straight: All cards are consecutive values.
    Flush: All cards of the same suit.
    Full House: Three of a kind and a pair.
    Four of a Kind: Four cards of the same value.
    Straight Flush: All cards are consecutive values of same suit.
    Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

 */

    unsigned long long score = 0;

    //Check high card
    int high = highCard(player);
    if (DEBUG == 1) printf("Highest card is %d\n", high);
    score += high;

    //See if pair
    int pair = isPair(player);
    if (pair){
        if (DEBUG == 1) printf("Pair of %d\n", pair);
        score += pair * 100;
    }

    //See if 2 pair
    int twoPair = isTwoPair(player);
    if (twoPair){
        if (DEBUG == 1) printf("2 pair, %d high\n", twoPair);
        score += twoPair * 10000;
    }

    //See if three of a kind
    int three = isThree(player);
    if (three){
        if (DEBUG == 1) printf("Three of %d\n", three);
        score += three * 1000000;
    }

    //See if straight
    int straight = isStraight(player);
    if (straight){
        if (DEBUG == 1) printf("Is Straight, %d high\n", straight);
        score += straight * 100000000;
    }

    //See if flush
    int flush = isFlush(player);
    if (flush){
        if (DEBUG == 1) printf("Flush\n");
        score += 1000000000;
    }

    //If two and three, full house!
    if (pair && three){
        if (DEBUG == 1) printf("Full house\n");
        score += 10000000000;
    }

    //See if four of a kind
    int four = isFour(player);
    if (four){
        if (DEBUG == 1) printf("Four of %d\n", four);
        score += 100000000000;
    }

    //See if straight flush
    if (flush && straight){
        if (DEBUG == 1) printf("Straight flush\n");
        score += 1000000000000;
    }

    //See if royal flush
    if (flush && straight == 14){
        if (DEBUG == 1) printf("Straight flush\n");
        score += 10000000000000;
    }

    return score;
}


int winner(deal deal)
{
/*
    //Debug Print
    int cardIndex=0, playerIndex=0;
    for (playerIndex = 0; playerIndex<2; playerIndex++)
    {
        printf("Player %d: ", playerIndex+1);
        for (cardIndex = 0; cardIndex<5; cardIndex++)
        {
            printf("(%d)%d, ",
                   deal.player[playerIndex].cards[cardIndex].suit,
                   deal.player[playerIndex].cards[cardIndex].value);
        }
        printf("\n");
    }
*/

    unsigned long long scoreA = handScore(deal.player[0]);
    unsigned long long scoreB = handScore(deal.player[1]);

    if (scoreA > scoreB)
        return 1;
    return 0;
}

int main()
{
    printf("Project Euler - Problem 54:\n"
           "Of the 1000 hands of poker represented in \"problem_054.txt,\" how many hands did player 1 win?\n\n");

    deal deals[1000];

    nameFile = fopen ("problem_054.txt", "rt");

    // Read in dealt hands to structure
    int ch, cardIndex=0, playerIndex=0, dealIndex=0;
    while((ch = fgetc(nameFile)))
    {
        if ( ch == EOF ) break;
        if ( ch == '\n' )
        {
            dealIndex++;
            cardIndex = 0;
            playerIndex = 0;
            continue;
        }
        if ( ch == ' ' )
        {
            cardIndex++;
            if (cardIndex == 5)
            {
                playerIndex = 1;
                cardIndex = 0;
            }
            continue;
        }

        //Get Value
        switch (ch)
        {
        case 'T':
        {
            ch = 10;
            break;
        }
        case 'J':
        {
            ch = 11;
            break;
        }
        case 'Q':
        {
            ch = 12;
            break;
        }
        case 'K':
        {
            ch = 13;
            break;
        }
        case 'A':
        {
            ch = 14;
            break;
        }
        default:
        {
            ch -= '0';
            break;
        }
        }
        deals[dealIndex].player[playerIndex].cards[cardIndex].value = ch;

        //Get Suit
        ch = fgetc(nameFile);
        switch (ch)
        {
        case 'S':
        {
            deals[dealIndex].player[playerIndex].cards[cardIndex].suit = 1;
            break;
        }
        case 'H':
        {
            deals[dealIndex].player[playerIndex].cards[cardIndex].suit = 2;
            break;
        }
        case 'D':
        {
            deals[dealIndex].player[playerIndex].cards[cardIndex].suit = 3;
            break;
        }
        case 'C':
        {
            deals[dealIndex].player[playerIndex].cards[cardIndex].suit = 4;
            break;
        }
        }
    }

    fclose(nameFile);

/*
    //Debug Print
    for (dealIndex = 0; dealIndex<1000; dealIndex++)
    {
        printf("Game #%d\n", dealIndex+1);
        for (playerIndex = 0; playerIndex<2; playerIndex++)
        {
            printf("Player %d: ", playerIndex+1);
            for (cardIndex = 0; cardIndex<5; cardIndex++)
            {
                printf("(%d)%d, ",
                       deals[dealIndex].player[playerIndex].cards[cardIndex].suit,
                       deals[dealIndex].player[playerIndex].cards[cardIndex].value);
            }
            printf("\n");
        }
        printf("\n");
    }
*/


    //Figure out who won.
    int wins = 0;
    for (dealIndex = 0; dealIndex < 1000; dealIndex++)
        if (winner(deals[dealIndex]) == 1)
            wins++;


    printf("Total hands won: %d\n", wins);
    return 0;
}
