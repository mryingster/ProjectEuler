#!/usr/bin/xcrun swift
// -*- compile-command: "xcrun -sdk macosx swiftc problem_054.swift -o problem_054_swift" -*-
// Copyright (c) 2016 Michael Caldwell
import Foundation

struct Card {
    var suit = 0
    var value = 0
}

struct Hand {
    var card:[Card]
}

struct Deal {
    var player:[Hand]
}


func isFlush(player:Hand) -> Bool {
    for i in 0 ..< 5 {
        if player.card[i].suit != player.card[0].suit {
            return false
        }
    }
    return true
}

func highCard(player: Hand) -> Int {
    var max = 0
    for i in 0 ..< 5 {
        if player.card[i].value > max {
            max = player.card[i].value
        }
    }
    return max as Int
}

func isStraight(player:Hand) -> Int {
    var min = 15

    for i in 0 ..< 5 {
        if player.card[i].value < min {
            min = player.card[i].value
        }
    }

    var max = 0
    for i in 0 ..< 5 {
        if player.card[i].value > max {
            max = player.card[i].value
        }
    }

    if (max - min) != 4 {
        return 0
    }

    var visited = [Int](repeating:0, count:5)
    for i in 0 ..< 5 {
        if visited[(player.card[i].value - min)] > 0 {
            return 0
        } else {
            visited[(player.card[i].value - min)] += 1
        }
    }

    return max as Int
}

func isPair(player:Hand) -> Int {
    var visited = [Int](repeating:0, count:16)
    for i in 0 ..< 5 {
        visited[(player.card[i].value)] += 1
    }

    for i in 0 ..< visited.count {
        if visited[i] == 2 {
            return i as Int
        }
    }

    return 0
}

func isTwoPair(player:Hand) -> Int {
    var visited = [Int](repeating:0, count:16)
    for i in 0 ..< 5 {
        visited[(player.card[i].value)] += 1
    }

    var count = 0
    for i in 0 ..< visited.count {
        if visited[i] == 2
        {
            if count == 1 {
                return i as Int
            } else {
                count += 1
            }
        }
    }

    return 0
}

func isThree(player:Hand) -> Int {
    var visited = [Int](repeating:0, count:16)
    for i in 0 ..< 5 {
        visited[(player.card[i].value)] += 1
    }

    for i in 0 ..< visited.count {
        if visited[i] == 3 {
            return i as Int
        }
    }

    return 0
}

func isFour(player:Hand) -> Int {
    var visited = [Int](repeating:0, count:16)
    for i in 0 ..< 5 {
        visited[(player.card[i].value)] += 1
    }

    for i in 0 ..< visited.count {
        if visited[i] == 4 {
            return i as Int
        }
    }

    return 0
}

func getScore(player:Hand, debug:Bool) -> Int {
    //Debug Print
    if debug == true {
        for i in 0 ..< 5 {
            print("(S:", player.card[i].suit,
                  " V:", player.card[i].value,
                  ") ", terminator:"")
        }
        print("")
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

    var score = 0

    //Check high card
    let high = highCard(player:player)
    if debug == true { print("Highest card is ", high) }
    score += high

    //See if pair
    let pair = isPair(player:player)
    if pair > 0 {
        if debug == true { print("Pair of ", pair) }
        score += pair * 100
    }

    //See if 2 pair
    let twoPair = isTwoPair(player:player)
    if twoPair > 0 {
        if debug == true { print("2 pair,  high", twoPair) }
        score += twoPair * 10000
    }

    //See if three of a kind
    let three = isThree(player:player)
    if three > 0 {
        if debug == true { print("Three of ", three) }
        score += three * 1000000
    }

    //See if straight
    let straight = isStraight(player:player)
    if straight > 0 {
        if debug == true { print("Is Straight,  high", straight) }
        score += straight * 100000000
    }

    //See if flush
    let flush = isFlush(player:player)
    if flush == true {
        if debug == true { print("Flush") }
        score += 1000000000
    }

    //If two and three, full house!
    if pair > 0 && three > 0{
        if debug == true { print("Full house") }
        score += 10000000000
    }

    //See if four of a kind
    let four = isFour(player:player)
    if four > 0{
        if debug == true { print("Four of ", four) }
        score += 100000000000
    }

    //See if straight flush
    if flush == true && straight > 0{
        if debug == true { print("Straight flush") }
        score += 1000000000000
    }

    //See if royal flush
    if flush == true && straight == 14{
        if debug == true { print("Royal flush") }
        score += 10000000000000
    }

    return score
}

func cardParse(card:String) -> Card {
    var parsedCard = Card()
    
    let value = card[card.startIndex]
    if value == "2" { parsedCard.value = 2 }
    if value == "3" { parsedCard.value = 3 }
    if value == "4" { parsedCard.value = 4 }
    if value == "5" { parsedCard.value = 5 }
    if value == "6" { parsedCard.value = 6 }
    if value == "7" { parsedCard.value = 7 }
    if value == "8" { parsedCard.value = 8 }
    if value == "9" { parsedCard.value = 9 }
    if value == "T" { parsedCard.value = 10 }
    if value == "J" { parsedCard.value = 11 }
    if value == "Q" { parsedCard.value = 12 }
    if value == "K" { parsedCard.value = 13 }
    if value == "A" { parsedCard.value = 14 }

    let suit = card[card.index(after: card.startIndex)]
    if suit == "S" { parsedCard.suit = 1 }
    if suit == "H" { parsedCard.suit = 2 }
    if suit == "D" { parsedCard.suit = 3 }
    if suit == "C" { parsedCard.suit = 4 }

    return parsedCard
}

print("Project Euler - Problem 54:")
print("Of the 1000 hands of poker represented in \"problem_054.txt,\" how many hands did player 1 win?\n")

let debug = false

// Import data from file
let file: FileHandle? = FileHandle(forReadingAtPath: "problem_054.txt")
if file == nil {
    print("Unable to open file.")
    exit(1)
}

// Read all the data
let data = file?.readDataToEndOfFile()

// Close the file
file?.closeFile()

// Convert our data to string
let dataAsString = String(data: data!, encoding: String.Encoding.utf8)

// Create structure for hand data
var deals = [Deal]()

// Separate hands and cards into array
var array = [String]()
var inputArray = dataAsString!.components(separatedBy:"\n")
for d in 0 ..< inputArray.count - 1{
    // Create temporary structures for the hand data
    var blankCard = Card(suit:0, value:0)
    var blankHand = Hand(card: [Card](repeating: blankCard, count: 5))
    var thisDeal = Deal(player: [Hand](repeating: blankHand, count: 2))

    // Split each deal into array
    var dealArray = inputArray[d].components(separatedBy:" ")

    // Parse each card and add it to the hand
    for c in 0 ..< dealArray.count{
        let player = c < 5 ? 0 : 1
        thisDeal.player[player].card[c%5] = cardParse(card: dealArray[c])
    }

    // Add thisDeal to deals
    deals.append(thisDeal)
}

// Tabulate wins!
var winsP1 = 0
for i in 0 ..< deals.count {
    let scoreP1 = getScore(player:deals[i].player[0], debug:debug)
    let scoreP2 = getScore(player:deals[i].player[1], debug:debug)

    if scoreP1 > scoreP2 {
        winsP1 += 1
    }
}

print(winsP1)

