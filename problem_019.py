#!/usr/bin/env python

print("Project Euler - Problem 19:")
print("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n")

import datetime

sum = 0
date = datetime.datetime(1901, 1, 1, 12, 00, 00, 00)
while date.year < 2001:
    if date.weekday() == 6 and date.day == 1: sum += 1
    date += datetime.timedelta(days=1)

print(sum)
