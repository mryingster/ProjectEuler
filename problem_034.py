#!/usr/bin/env python

print("Project Euler - Problem 34:")
print("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

dict={"0":factorial(0), "1":factorial(1), "2":factorial(2),
      "3":factorial(3), "4":factorial(4), "5":factorial(5),
      "6":factorial(6), "7":factorial(7), "8":factorial(8),
      "9":factorial(9)}

answer = 0
limit = 100000
for n in range(10, limit):
    s = 0
    for d in str(n):
        s += dict[d]
    if n == s:
        answer += n

print(answer)
