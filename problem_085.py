#!/usr/bin/env python

print("Project Euler - Problem 85")
print("Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.\n")

closeness = 10000000
closearea = 0
closex = 0
closey = 0
debug = False

for x in range(1, 2000):
    for y in range(1, 2000):
        area = x * y
        if area > 3000: continue
        rectangles = 0
        for m in range(1, x+1):
            for n in range(1, y+1):
                rectangles += (x - m + 1) * (y - n + 1)

        if debug == True: print x, y, area, rectangles

        if abs(2000000 - rectangles) < closeness:
            closeness = abs(2000000 - rectangles)
            closearea = area
            closex = x
            closey = y

print("Grid area: %d (%d x %d, %d away from two million)" % (closearea, closex, closey, closeness))
