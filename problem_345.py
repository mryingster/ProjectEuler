#!/usr/bin/env python

def printArray(array):
    for row in array:
        for e in row:
            print("%3d"% e),
        print("")
    print("")

print("Project Euler: 345")
print("We define the Matrix Sum of a matrix as the maximum sum of matrix elements with each element being the only one in his row and column. Find the Matrix Sum of the 15 x 15 array\n")

master = [[  7,  53, 183, 439, 863, 497, 383, 563,  79, 973, 287,  63, 343, 169, 583],
          [627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913],
          [447, 283, 463,  29,  23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743],
          [217, 623,   3, 399, 853, 407, 103, 983,  89, 463, 290, 516, 212, 462, 350],
          [960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350],
          [870, 456, 192, 162, 593, 473, 915,  45, 989, 873, 823, 965, 425, 329, 803],
          [973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326],
          [322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601,  95, 973],
          [445, 721,  11, 525, 473,  65, 511, 164, 138, 672,  18, 428, 154, 448, 848],
          [414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198],
          [184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390],
          [821, 461, 843, 513,  17, 901, 711, 993, 293, 157, 274,  94, 192, 156, 574],
          [ 34, 124,   4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699],
          [815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107],
          [813, 883, 451, 509, 615,  77, 281, 613, 459, 205, 380, 274, 302,  35, 805]]

printArray(master)

test  = False # Use Test Matrix
debug = False # Print out helpful information

if test == True:
    master = [[  7,  53, 183, 439, 863],
              [497, 383, 563,  79, 973],
              [287,  63, 343, 169, 583],
              [627, 343, 773, 959, 943],
              [767, 473, 103, 699, 303]]


# Copy the master array to work on
array = []
for row in master:
    newRow = []
    for e in row:
        newRow.append(e)
    array.append(newRow)

# Print Starting Array
if debug == True:
    print("Starting Values")
    printArray(array)

# Find Maximum Value in each Row, increase values of all until max == 999
for row in array:
    maximum = 999-max(row)
    for i in range(len(row)):
        row[i] += maximum

# Print array with each row adjusted
if debug == True:
    print("Rows Maxed")
    printArray(array)

# Find Maximum Value in each Column, increase values of all until max == 999
for col in range(len(array)):
    tempColumn = []
    for row in range(len(array)):
        tempColumn.append(array[row][col])
    maximum = 999-max(tempColumn)
    for row in range(len(array)):
        array[row][col] += maximum

# Print array with adjusted column values
if debug == True:
    print("Columns Maxed")
    printArray(array)

solved = False
while solved == False:
    # Mask is to "cover up" data
    # 0 means not covered
    # 1 covered in one dimension
    # 2 covered in two dimensions
    mask = []
    for y in range(len(array)):
        row = []
        for x in range(len(array)):
            row.append(0)
        mask.append(row)

    # Check each cell and cover up cols or rows
    coverCount = 0
    for x in range(len(array)):
        for y in range(len(array)):
            # Only check on cells with exposed 999 value
            if array[y][x] != 999 or mask[y][x] != 0:
                continue

            # Keep track of how many rows/cols we've covered.
            coverCount += 1

            # Look for exposed 999s in cols and rows
            rowCount, uncoveredRowCount = 0, 0
            colCount, uncoveredColCount = 0, 0
            for z in range(len(array)):
                if array[z][x] == 999:
                    rowCount += 1
                    if mask[z][x] == 0:
                        uncoveredRowCount += 1
                if array[y][z] == 999:
                    colCount += 1
                    if mask[y][z] == 0:
                        uncoveredColCount += 1

            # Cover up row/col with uncovered values (Row precedence)
            if uncoveredRowCount > 1:
                for z in range(len(array)):
                    mask[z][x] += 1
                continue
            if uncoveredColCount > 1:
                for z in range(len(array)):
                    mask[y][z] += 1
                continue

            # Cover up row/col with uncovered or covered values (Row precedence)
            if rowCount > 1:
                for z in range(len(array)):
                    mask[z][x] += 1
                continue
            if colCount > 1:
                for z in range(len(array)):
                    mask[y][z] += 1
                continue

            # If no other 999s in row or col, arbitrarily cover column
            for z in range(len(array)):
                mask[y][z] += 1

    # If number of rows/cols covered == size of array, finished!
    if debug == True:
        print("Columns & Rows covered: %d/%d" % (coverCount, len(array)))
        printArray(mask)

    if coverCount == len(array): break

    # Find max value that is not covered
    tmp = []
    for y in range(len(array)):
        for x in range(len(array)):
            if mask[y][x] == False:
                tmp.append(array[y][x])
    maxValue = 999-max(tmp)

    # Subtract value from covered cells (2x for overlapping)
    for y in range(len(array)):
        for x in range(len(array)):
            while mask[y][x] > 0:
                array[y][x] -= maxValue
                mask[y][x] -= 1

    # Add value to all cells
    for y in range(len(array)):
        for x in range(len(array)):
            array[y][x] += maxValue

    # Start over
    if debug == True: printArray(array)

# Now that we have the potential Max Values, try to isolate them to one per row/column
# Try it twice
for i in range(2):
    for y in range(len(array)):
        for x in range(len(array)):
            if array[y][x] != 999: continue

            # Check If only option in row/col
            colCount = 0
            rowCount = 0
            for z in range(len(array)):
                if array[y][z] == 999:
                    colCount += 1
                if array[z][x] == 999:
                    rowCount += 1

            # Erase remainging options in col/row
            if colCount == 1:
                for z in range(len(array)):
                    if z != y:
                        array[z][x] -= 10
            if rowCount == 1:
                for z in range(len(array)):
                    if z != x:
                        array[y][z] -= 10
                continue

    # Print the 999 in each column/row
    if debug == True:
        print("Remaining Values")
        for y in range(len(array)):
            for x in range(len(array)):
                if array[y][x] == 999:
                    print("%3d"% master[y][x]),
                else:
                    print("  -"),
            print("")
        print("")

# Sum up the answer!
answer = 0
for y in range(len(array)):
    for x in range(len(array)):
        if array[y][x] == 999:
            answer += master[y][x]

print(answer)

if test == True and answer != 3315:
    print("Incorrect :(")
