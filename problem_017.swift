#!/usr/bin/xcrun swift
// -*- compile-command: "swiftc problem_017.swift -o problem_017" -*-
// Copyright (c) 2016 Michael Caldwell

print("Project Euler - Problem 17:")
print("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used\n")

func numLen(n:Int) -> Int {
    switch n {
    case 1:  return 3 // one
    case 2:  return 3 // two
    case 3:  return 5 // three
    case 4:  return 4 // four
    case 5:  return 4 // five
    case 6:  return 3 // six
    case 7:  return 5 // seven
    case 8:  return 5 // eight
    case 9:  return 4 // nine
    case 10: return 3 // ten
    case 11: return 6 // eleven
    case 12: return 6 // twelve
    case 13: return 8 // thirteen
    case 14: return 8 // fourteen
    case 15: return 7 // fifteen
    case 16: return 7 // sixteen
    case 17: return 9 // seventeen
    case 18: return 8 // eighteen
    case 19: return 8 // nineteen
    case 20: return 6 // twenty
    case 30: return 6 // thirty
    case 40: return 5 // forty
    case 50: return 5 // fifty
    case 60: return 5 // sixty
    case 70: return 7 // seventy
    case 80: return 6 // eighty
    case 90: return 6 // ninety
    default: break
    }
    return 0
}

var sum = 0

for i in 1...1000 {
    var n = i

    if n > 999 {
        sum += numLen(n / 100)
        sum += 8 // thousand
        n %= 1000
    }

    if n > 99 {
        sum += numLen(n / 100)
        sum += 7 // hundred
        n %= 100
        if n != 0 {
            sum += 3 // and
        }
    }

    if n < 21 {
        sum += numLen(n)
    } else {
        sum += numLen((n/10)*10)
        sum += numLen(n%10)
    }
}

print(sum)
