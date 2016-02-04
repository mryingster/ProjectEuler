#!/usr/bin/env python

print("Project Euler - Problem 30:")
print("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

exp = 5
limit = 6*9 ** exp
dict={"0":0**exp, "1":1**exp, "2":2**exp, "3":3**exp,
      "4":4**exp, "5":5**exp, "6":6**exp, "7":7**exp,
      "8":8**exp, "9":9**exp}

answer = 0
for n in range(2, limit):
    s = 0
    for d in str(n):
        s += dict[d]
    if n == s:
        answer += n

print(answer)
