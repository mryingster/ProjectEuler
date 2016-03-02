#!/usr/bin/env python

print("Project Euler - Problem 40:")
print("If dn represents the nth digit of an irrational fraction created by concatenating the positive integers, find the value of the following expression:\n\nd1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000\n")

string = ""
n = 1
while len(string) < 1000001:
    string += str(n)
    n += 1

answer = 1
for e in range(0, 7):
    answer *= int(string[pow(10, e)-1])

print answer

