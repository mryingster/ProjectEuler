#!/usr/bin/env python

print("Project Euler: 74")
print("How many factorial chains, with a starting number below one million, contain exactly sixty non-repeating terms?\n")

Factorials = {}

def Factorial(Input):
    Output = 1
    if Input in Factorials:
        return Factorials[Input]
    for i in range(1, Input + 1):
        Output = Output*i
    Factorials.update({Input:Output})
    return Output

def Digits(Input):
    Temp = Input
    Output = 0
    while Temp > 0:
        Output += Factorial(Temp % 10)
        Temp = Temp / 10
    return Output

#Main Variables
Count = 0
History = {}

for i in range(1, 1000000):
    #print i,
    NumbersEncountered = [i]
    LoopCount = 1
    CurrentNum = Digits(i)
    while not CurrentNum in NumbersEncountered:
        #print CurrentNum,
        LoopCount += 1
        NumbersEncountered.append(CurrentNum)
        CurrentNum = Digits(CurrentNum)
        if CurrentNum in History:
            LoopCount += History[CurrentNum]
            break

    #print("Count: %d" %str(LoopCount))
    if LoopCount == 60:
        #print i
        Count += 1
    History.update({i:LoopCount})

print("Chains with 60 terms: %d" % Count)

