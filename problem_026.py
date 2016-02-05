#!/usr/bin/env python

print("Project Euler - Problem 26")
print("Find the value of d < 1000 for which 1/d contains the longest recurring cycle.\n")

longest = [0, 0]
debug = False

for d in range(2, 1000):
    answer = [1]
    i = 0
    repeat = 1
    repeatLength = -1

    # Perform long division
    while len(answer) < 1500:
        tmp = answer[i]/d
        tmp2 = tmp*d
        answer[i] -= tmp2
        answer.append(0)
        if answer[i] < d:
            answer[i+1] += answer[i]*10
            answer[i] = 0
        answer[i] = tmp

        # Keep track if repeating digits.
        if len(answer) > 3:
            if answer[i] == answer[repeat]:
                repeat += 1
            else:
                repeat = 1
        if repeat >= 10:
            repeatLength = i-repeat+1
            if repeatLength > longest[0]:
                longest[0] = repeatLength
                longest[1] = d
            break

        i += 1

    # Print answers
    if debug == True:
        print("1/%d repeats after %d digits" % (d, repeatLength))
        print(answer)

print(longest[1])
