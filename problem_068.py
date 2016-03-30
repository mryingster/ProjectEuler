#!/usr/bin/python
import itertools, sys

print("Project Euler - Problem 68:")
print("Find the maximum concatenation for a 16 digit string for a solution to a \"magic 5-gon ring\" using the numbers 1-10?\n")

inner = [1,2,3,4,5]
# Largest solution needs to have all 5 largest numbers in the outer ring
# Need to have 10 in the outer ring as well since we need 16 digit solution
outer = [6,7,8,9,10]

solutions = []
for i in itertools.permutations(inner):
    for o in itertools.permutations(outer):
        # Number has to start with smallest outer ring digit...
        if o[0] != 6: continue

        # Build our solution string
        solution = [o[0],i[0],i[1],
                    o[1],i[1],i[2],
                    o[2],i[2],i[3],
                    o[3],i[3],i[4],
                    o[4],i[4],i[0]]

        # Check if each leg has same total
        solved = True
        total = sum(solution[0:3])
        for n in range(0,15,3):
            if sum(solution[n:n+3]) != total:
                solved = False

        # save solution
        if solved == True:
            solutions.append(solution)

# Last solution added will be greatest
# (based on how the permutations are generated)
for d in solutions[-1]:
    sys.stdout.write(str(d))
print("")

