#!/usr/bin/env python

def brute_force(e, m, limit):
    coins = []
    last_index = 1
    index = 1
    coin = 0
    while index < limit:
        index += 1
        coin += e
        coin %= m
        if len(coins) == 0 or coin < coins[-1]:
            coins.append(coin)
            print("index:%8s interval:%8s  (%s)" % (index, index-last_index, coin))
            last_index = index
    return coins

def xgcd(a,b):
    m = []
    prevx, x = 1, 0
    prevy, y = 0, 1
    while b:
        q = a/b
        x, prevx = prevx - q*x, x
        y, prevy = prevy - q*y, y
        a, b = b, a % b
        if x < 0:
            m.append(x * -1)
    return m

def find_eulercoins(seed, mod, intervals):
    coins = [seed]
    coin = 0
    euler_index = 1
    interval_index = 0
    while interval_index < len(intervals):
        t = euler_index
        t += intervals[interval_index]
        coin = t * seed
        coin %= mod
        if len(coins) == 0 or coin < coins[-1]:
            coins.append(coin)
            euler_index = t
            continue
        interval_index += 1
    return coins

def __main__():
    e = 1504170715041707
    m = 4503599627370517

    print("Project Euler - Problem 700:")
    print("Consider the sequence 1504170715041707n mod 4503599627370517. The first term is 1504170715041707 which is the first Eulercoin. The second term is 3008341430083414 which is greater than 1504170715041707 so is not an Eulercoin. However, the third term is 8912517754604 which is small enough to be a new Eulercoin. Find the sum of all Eulercoins.\n")

    # Brute force method for examining how the eulercoins trend
    #brute_force(e, m, 10**6)

    # Use the xgdc to get the intervals between eulercoins!
    # http://anh.cs.luc.edu/331/notes/xgcd.pdf
    intervals = xgcd(e, m)

    # Find the coins by incrementing the eulercoin index
    # by the interval ammounts found above
    coins = find_eulercoins(e, m, intervals)

    print sum(coins)

__main__()
