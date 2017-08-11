#!/usr/bin/env python

print("Project Euler 173:")
print("We shall define a square lamina to be a square outline with a square \"hole\" so that the shape possesses vertical and horizontal symmetry. Using up to one million tiles how many different square laminae can be formed?\n")

limit = 1000000
count = 0
debug = False

#
# ##### Wall thickness = 2
# ##### Inside length = 1
# ## ## Blocks used = Wall thickness * inside length * 4 + Wall thickness^2 * 4 
# #####             = (2 * 1 * 4) + (2^2 * 4)
# #####             = 8 + 16 = 24
#

for thickness in range(1, limit):
    # Start with inside length of 1
    squares = (4 * thickness) + (4 * thickness ** 2)

    while squares <= limit:
        count += 1

        if debug == True:
            print inside, thickness, squares

        # Increase inside length
        squares += thickness * 4

print count
