#!/usr/bin/env python

print("Project Euler - Problem 17:")
print("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?\n")

dict={1: "one",
      2: "two",
      3: "three",
      4: "four",
      5: "five",
      6: "six",
      7: "seven",
      8: "eight",
      9: "nine",
      10:"ten",
      11:"eleven",
      12:"twelve",
      13:"thirteen",
      14:"fourteen",
      15:"fifteen",
      16:"sixteen",
      17:"seventeen",
      18:"eighteen",
      19:"nineteen",
      20:"twenty",
      30:"thirty",
      40:"forty",
      50:"fifty",
      60:"sixty",
      70:"seventy",
      80:"eighty",
      90:"ninety"}

string=""

for i in range(1, 1001):
    if i > 999:
        string += dict[int(i/1000)]
        string += "thousand"
        i %= 1000
        if i == 0: continue

    if i > 99:
        string += dict[int(i/100)]
        string += "hundred"
        i %= 100
        if i == 0: continue
        string += "and"

    if i in dict:
        string += dict[i]
        continue

    string += dict[int(i/10)*10]
    string += dict[int(i%10)]

print len(string)
