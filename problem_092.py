#!/usr/bin/python

print("Project Euler - Problem 92:")
print("A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before. How many starting numbers below ten million will arrive at 89?\n")

Count=0
History={}

for i in range (1, 10000000):
    Number = i

    while 1:
        # Add to dictionary if new
        if Number == 1:
            History.update({i:1})
            break
        if Number == 89:
            History.update({i:89})
            Count += 1
            break

        # Check dictionary for short cut
        if Number in History:
            Number = History[Number]

        # Boil it down
        else:
            Temp = str(Number)
            Addition = 0
            for n in range(len(Temp)):
                Addition += int(Temp[n]) * int(Temp[n])

            Number = Addition

print(str(Count))
