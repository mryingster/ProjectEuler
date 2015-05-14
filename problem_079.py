#!/usr/bin/python

print("Project Euler: 79")
print("Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.\n")

Before1 = []
Before2 = []
Before3 = []
Before6 = []
Before7 = []
Before8 = []
Before9 = []
Before0 = []

ReadFile = open("problem_079.txt")
while 1:
    Line = ReadFile.readline()
    if not Line: break
    Line = Line[0:3]
    #print Line

    Digit1 = Line[0]
    Digit2 = Line[1]
    Digit3 = Line[2]

    if   Digit2 == "1": Before1.append(Digit1)
    elif Digit2 == "2": Before2.append(Digit1)
    elif Digit2 == "3": Before3.append(Digit1)
    elif Digit2 == "6": Before6.append(Digit1)
    elif Digit2 == "7": Before7.append(Digit1)
    elif Digit2 == "8": Before8.append(Digit1)
    elif Digit2 == "9": Before9.append(Digit1)
    elif Digit2 == "0": Before0.append(Digit1)

    if   Digit3 == "1": Before1.append(Digit2)
    elif Digit3 == "2": Before2.append(Digit2)
    elif Digit3 == "3": Before3.append(Digit2)
    elif Digit3 == "6": Before6.append(Digit2)
    elif Digit3 == "7": Before7.append(Digit2)
    elif Digit3 == "8": Before8.append(Digit2)
    elif Digit3 == "9": Before9.append(Digit2)
    elif Digit3 == "0": Before0.append(Digit2)

# Make lists unique
Before1 = list(set(Before1))
Before2 = list(set(Before2))
Before3 = list(set(Before3))
Before6 = list(set(Before6))
Before7 = list(set(Before7))
Before8 = list(set(Before8))
Before9 = list(set(Before9))
Before0 = list(set(Before0))

Answer = []
while 1:
    for i in 1, 2, 3, 6, 7, 8, 9, 0:
        if len(eval("Before"+str(i)))==0:
            if not i in Answer:
                #print i
                Answer.append(i)
                break
        for n in range(len(Answer)):
            if str(Answer[n]) in eval("Before"+str(i)):
                PopMe=eval("Before"+str(i)).index(str(Answer[n]))
                eval("Before"+str(i)).pop(PopMe)
    if len(Answer) == 8:
        break

print Answer
