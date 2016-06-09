// -*- compile-command: "rustc -o problem_054_rs problem_054.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

#[derive(Copy, Clone)]
struct Card {
    suit: u32,
    value: u32,
}

#[derive(Copy, Clone)]
struct Hand {
    card: [Card; 5],
}

#[derive(Copy, Clone)]
struct Deal {
    player: [Hand; 2],
}

fn is_flush(player:Hand) -> bool {
    for i in 0..5 {
        if player.card[i].suit != player.card[0].suit {
            return false;
        }
    }
    return true;
}

fn high_card(player: Hand) -> u64 {
    let mut max = 0;
    for i in 0..5 {
        if player.card[i].value > max {
            max = player.card[i].value;
        }
    }
    return max as u64;
}

fn is_straight(player:Hand) -> u64 {
    let mut min = 15;

    for i in 0..5 {
        if player.card[i].value < min {
            min = player.card[i].value;
        }
    }

    let mut max = 0;
    for i in 0..5 {
        if player.card[i].value > max {
            max = player.card[i].value;
        }
    }

    if (max - min) != 4 {
        return 0;
    }

    let mut visited = [0; 5];
    for i in 0..5 {
        if visited[(player.card[i].value - min) as usize] > 0 {
            return 0;
        } else {
            visited[(player.card[i].value - min) as usize] += 1;
        }
    }

    return max as u64;
}

fn is_pair(player:Hand) -> u64 {
    let mut visited = [0; 16];
    for i in 0..5 {
        visited[(player.card[i].value) as usize] +=1;
    }

    for i in 0..visited.len() {
        if visited[i] == 2 {
            return i as u64;
        }
    }

    return 0;
}

fn is_two_pair(player:Hand) -> u64 {
    let mut visited = [0; 16];
    for i in 0..5 {
        visited[(player.card[i].value) as usize] += 1;
    }

    let mut count = 0;
    for i in 0..visited.len() {
        if visited[i] == 2
        {
            if count == 1 {
                return i as u64;
            } else {
                count += 1;
            }
        }
    }

    return 0;
}

fn is_three(player:Hand) -> u64 {
    let mut visited = [0; 16];
    for i in 0..5 {
        visited[(player.card[i].value) as usize] += 1;
    }

    for i in 0..visited.len() {
        if visited[i] == 3 {
            return i as u64;
        }
    }

    return 0;
}

fn is_four(player:Hand) -> u64 {
    let mut visited = [0; 16];
    for i in 0..5 {
        visited[(player.card[i].value) as usize] += 1;
    }

    for i in 0..visited.len() {
        if visited[i] == 4 {
            return i as u64;
        }
    }

    return 0;
}

fn get_score(player:Hand) -> u64 {
    let debug = 0;

    if debug == 1 {
        //Debug Print
        for card_index in 0..5 {
            print!("({}){}, ",
                   player.card[card_index].suit,
                   player.card[card_index].value);
        }
        println!("");
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

    let mut score:u64 = 0;

    //Check high card
    let high = high_card(player);
    if debug == 1 { println!("Highest card is {}", high); }
    score += high;

    //See if pair
    let pair = is_pair(player);
    if pair > 0 {
        if debug == 1 { println!("Pair of {}", pair); }
        score += pair * 100;
    }

    //See if 2 pair
    let two_pair = is_two_pair(player);
    if two_pair > 0 {
        if debug == 1 { println!("2 pair, {} high", two_pair); }
        score += two_pair * 10000;
    }

    //See if three of a kind
    let three = is_three(player);
    if three > 0 {
        if debug == 1 { println!("Three of {}", three); }
        score += three * 1000000;
    }

    //See if straight
    let straight = is_straight(player);
    if straight > 0 {
        if debug == 1 { println!("Is Straight, {} high", straight); }
        score += straight * 100000000;
    }

    //See if flush
    let flush = is_flush(player);
    if flush == true {
        if debug == 1 { println!("Flush"); }
        score += 1000000000;
    }

    //If two and three, full house!
    if pair > 0 && three > 0{
        if debug == 1 { println!("Full house"); }
        score += 10000000000;
    }

    //See if four of a kind
    let four = is_four(player);
    if four > 0{
        if debug == 1 { println!("Four of {}", four); }
        score += 100000000000;
    }

    //See if straight flush
    if flush == true && straight > 0{
        if debug == 1 { println!("Straight flush"); }
        score += 1000000000000;
    }

    //See if royal flush
    if flush == true && straight == 14{
        if debug == 1 { println!("Royal flush"); }
        score += 10000000000000;
    }

    return score;
}


fn main() {
    println!("Project Euler - Problem 54:");
    println!("Of the 1000 hands of poker represented in \"problem_054.txt,\" how many hands did player 1 win?\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_054.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Create structure for hand data
    let mut deals: Vec<Deal> = Vec::new();

    let temp_card = Card {suit: 0, value: 0};
    let temp_hand = Hand {card: [temp_card; 5]};
    let mut temp_deal = Deal {player: [temp_hand; 2]};

    let mut player = 0;
    let mut card = 0;

    for c in data.chars() {
        if c == ' ' { continue; }

        // New line, new hand
        if c == '\n' {
            deals.push(temp_deal);
            player = 0;
            card = 0;
            continue;
        }

        // Value, then Suit
        if c == '2' { temp_deal.player[player].card[card].value = 2 }
        if c == '3' { temp_deal.player[player].card[card].value = 3 }
        if c == '4' { temp_deal.player[player].card[card].value = 4 }
        if c == '5' { temp_deal.player[player].card[card].value = 5 }
        if c == '6' { temp_deal.player[player].card[card].value = 6 }
        if c == '7' { temp_deal.player[player].card[card].value = 7 }
        if c == '8' { temp_deal.player[player].card[card].value = 8 }
        if c == '9' { temp_deal.player[player].card[card].value = 9 }
        if c == 'T' { temp_deal.player[player].card[card].value = 10 }
        if c == 'J' { temp_deal.player[player].card[card].value = 11 }
        if c == 'Q' { temp_deal.player[player].card[card].value = 12 }
        if c == 'K' { temp_deal.player[player].card[card].value = 13 }
        if c == 'A' { temp_deal.player[player].card[card].value = 14 }

        if c == 'S' { temp_deal.player[player].card[card].suit = 1 }
        if c == 'H' { temp_deal.player[player].card[card].suit = 2 }
        if c == 'D' { temp_deal.player[player].card[card].suit = 3 }
        if c == 'C' { temp_deal.player[player].card[card].suit = 4 }

        // When we see a suit, we have a complete card.
        if c == 'D' || c == 'S' || c == 'C' || c == 'H' {
            card += 1;
            if card == 5 {
                card = 0;
                player = 1;
            }
        }
    }

    let mut wins = 0;
    for i in 0..deals.len() {
        let player_1_score = get_score(deals[i].player[0]);
        let player_2_score = get_score(deals[i].player[1]);

        if player_1_score > player_2_score {
            wins += 1;
        }
    }

    println!("{}", wins);
}
