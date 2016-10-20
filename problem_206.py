#!/usr/bin/python
import re

print("Project Euler: 206")
print("Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0, where each '_' is a single digit.\n")

Number = 1010101010
debug = False

while 1:
    Number += 10
    Square = Number ** 2
    if debug == True:
        print(Number, Square)

    #Skip irrelevent cases more quickly
    if not re.compile("1.2................").match(str(Square)):
        Number += 10000
    if not re.compile("1...3..............").match(str(Square)):
        Number += 1000
    if not re.compile("1.....4............").match(str(Square)):
        Number += 100

    #Find a winner!
    if re.compile("1.2.3.4.5.6.7.8.9.0").match(str(Square)):
        break

    #Gone too far! Whoops!
    if int(Square) > 2000000000000000000:
        print "You have failed :("
        quit()

print Number
