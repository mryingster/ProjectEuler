#!/usr/bin/env python

print("Project Euler - Problem 205:")
print("To 7 decimal places, what is the probablilty of 9 four-sided dice rolling a higher number than 6 six-sided dice?\n")

debug = False

# Calculate ways of achieving sums for 6 to 36
# P has 9 4 sided dice
P = [0, 0, 0]
for n in range(9, 23):
    PD = [0, 1, 1, 1, 1, 1, 1, 1, 1]
    PDC = 0
    while 1:
        PD[0] += 1
        for i in range(len(PD)-1):
            if PD[i] > 4:
                PD[i] = 1
                PD[i+1] += 1
        if PD[8] == 5:
            P.append(PDC)
            break
        PDS = 0
        for i in range(len(PD)):
            PDS += PD[i]
        if PDS == n:
            PDC += 1

# And add in reverse of numbers since symmetrical
for i in reversed(range(len(P))):
    P.append(P[i])

if debug == True: print P

# C has 6 6 sided dice
C = []
for n in range(6, 22):
    CD = [0, 1, 1, 1, 1, 1]
    CDC = 0
    while 1:
        CD[0] += 1
        for i in range(len(CD)-1):
            if CD[i] > 6:
                CD[i] = 1
                CD[i+1] += 1
        if CD[5] == 7:
            C.append(CDC)
            break
        CDS = 0
        for i in range(len(CD)):
            CDS += CD[i]
        if CDS == n:
            CDC += 1

# And add in reverse of numbers since symmetrical
for i in reversed(range(len(C)-1)):
    C.append(C[i])

if debug == True: print C

Wins = 0
Total = (4**9) * (6**6)

for c in range(0, 31):
    for p in range(c+1, 31):
        Wins += P[p] * C[c]

score = float(1.0 * Wins / Total)

print("Probability: %f" % round(score,7))
