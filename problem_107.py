#!/usr/bin/env python

print("Project Euler - Problem 107")
print("Using problem_107.txt, a 6K text file containing a network with forty vertices, find the maximum saving which can be achieved by removing redundant edges whilst ensuring that the network remains connected.\n")

debug = False
array = []

# Read file in, and put all values into a 2D array
with open("problem_107.txt") as file:
    while True:
        lineIn = file.readline()
        lineIn = lineIn.strip()
        if lineIn == "": break
        lineIn = lineIn.split(",")
        lineOut = []
        for e in lineIn:
            if e == "-":
                e = "0"
            lineOut.append(int(e))
        array.append(lineOut)

# Print the grid
if debug == True:
    for line in array:
        for e in line:
            print("%3d" % e),
        print("")


# Create a dictionary with the path (coordinates) and the weight
dict = {}
for a in range(len(array)):
    for b in range(a, len(array)):
        if array[a][b] != 0:
            name = str(a)+":"+str(b)
            value = array[a][b]
            dict.update({name:value})

# Sort the dictionary by weight
forest = []
savings = 0
for i in sorted(dict, key=dict.get):
    # Keep track of nodes visited
    a, b = i.split(":")
    a = int(a)
    b = int(b)

    processed = False
    # If tree already contains both values, it's not usable
    for tree in forest:
        if a in tree and b in tree:
            savings += dict[i]
            processed = True
            break
    if processed == True: continue

    # See if 2 trees can be combined
    for n in range(len(forest)):
        for j in range(len(forest)):
            if n == j: continue
            if a in forest[n] and b in forest[j]:
                forest[n] += forest[j]
                forest.pop(j)
                processed = True
                break
        if processed == True: break
    if processed == True: continue

    # Add value if an existing tree already has at least one of the values
    for tree in forest:
        if a in tree:
            tree.append(b)
            processed = True
            break
        if b in tree:
            tree.append(a)
            processed = True
            break
    if processed == True: continue

    # If doesn't connect to any existing tree, create new tree in forest
    forest.append([a, b])

    # Debug
    if debug == True:
        print(i, dict[i], savings)

if debug == True:
    print(forest)

print(savings)


