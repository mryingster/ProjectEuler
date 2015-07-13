#!/usr/bin/env python

print("Project Euler - Problem 109:")
print("In a standard game of darts, how many distinct ways can a player check out with a score less than 100?\n")

scores = [ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,25, # Single
           3, 6, 9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,    # Triple
           2, 4, 6, 8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,50] # Double

double = 41 # Doubles start at index 41
count = 0
debug = False

for score in range(2, 100):
    # Throw 1
    for a in range(len(scores)):
        total = scores[a]
        if total > score: continue
        if total == score and a >= double:
            count += 1
            if debug == True:
                print ("%d (%d)" % (total, scores[a]))

        # Throw 2
        for b in range(len(scores)):
            total = scores[a] + scores[b]
            if total < score and b < a: continue
            if total > score: continue
            if total == score and b >= double:
                count += 1
                if debug == True:
                    print ("%d (%d, %d)" % (total, scores[a], scores[b]))

            # Throw 3
            for c in range(double, len(scores)):
                total = scores[a] + scores[b] + scores[c]
                if total != score: continue
                count += 1
                if debug == True:
                    print ("%d (%d, %d, %d)" % (total, scores[a], scores[b], scores[c]))

print("%d ways" % count)
