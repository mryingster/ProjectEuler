#!/usr/bin/python

def isFlush(hand):
    for card in range(len(hand)-1):
        if hand[card][1] != hand[card+1][0]:
            return False
    return True

def highCard(hand):
    value = []
    for card in hand:
        value.append(card[0])
    return max(value)

def isStraight(hand):
    value = []
    for card in hand:
        value.append(card[0])
    value = sorted(value)
    for i in range(len(value)-1):
        if value[i] != value[i+1]-1:
            return 0
    return value[-1]

def isPair(hand, size, sets):
    seen = [0] * 15
    for card in hand:
        seen[card[0]] += 1
    times = 0
    for value in range(len(seen)):
        if seen[value] == size:
            times += 1
            if times == sets:
                return value
    return 0

def handScore(hand):
    # High Card: Highest value card.
    # One Pair: Two cards of the same value.
    # Two Pairs: Two different pairs.
    # Three of a Kind: Three cards of the same value.
    # Straight: All cards are consecutive values.
    # Flush: All cards of the same suit.
    # Full House: Three of a kind and a pair.
    # Four of a Kind: Four cards of the same value.
    # Straight Flush: All cards are consecutive values of same suit.
    # Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

    score = 0

    # Check high card
    score += highCard(hand)

    # See if pair
    pair = isPair(hand, 2, 1)
    score += pair * 100

    # See if 2 pair
    score += isPair(hand, 2, 2) * 10000

    # See if three of a kind
    three = isPair(hand, 3, 1)
    score += three * 1000000

    # See if straight
    straight = isStraight(hand)
    score += straight * 100000000

    # See if flush
    flush =  isFlush(hand)
    score += flush * 1000000000

    # If two and three, full house!
    if pair and three:
        score += 10000000000

    # See if four of a kind
    score += isPair(hand, 4, 1) * 100000000000;

    # See if straight flush
    if flush and straight:
        score += 1000000000000

    # See if royal flush
    if flush and straight == 14:
        score += 10000000000000;

    return score

print("Project Euler - Problem 54:")
print("Of the 1000 hands of poker represented in \"problem_054.txt,\" how many hands did player 1 win?\n")

hands=[]

# Read file in, and put all hands into a list
with open("problem_054.txt") as file:
    while True:
        line = file.readline()
        line = line.strip()
        if line == "": break
        line = line.split(" ")
        player1 = []
        player2 = []

        # Convert each hand to a 2 element array of digits for suit and value
        for card in line:
            newCard = []
            for char in card:
                if   char == "S":
                    newCard.append(0)
                elif char == "H":
                    newCard.append(1)
                elif char == "D":
                    newCard.append(2)
                elif char == "C":
                    newCard.append(3)
                elif char == "T":
                    newCard.append(10)
                elif char == "J":
                    newCard.append(11)
                elif char == "Q":
                    newCard.append(12)
                elif char == "K":
                    newCard.append(13)
                elif char == "A":
                    newCard.append(14)
                else:
                    newCard.append(int(char))
            if line.index(card) < 5:
                player1.append(newCard)
            else:
                player2.append(newCard)
        hands.append([player1, player2])

wins = 0
for hand in hands:
    if handScore(hand[0]) > handScore(hand[1]):
        wins += 1

print(wins)
