#!/bin/env lua

print("Project Euler - Problem 21:")
print("Evaluate the sum of all the amicable numbers under 10000.\n")

limit = 10000

-- Initialize array
sums = {0}
for i=1, limit do
   sums[i] = 0
end

-- Calculate divisor sums
for i = 1, limit do
   n = i + i
   while n < limit do
      sums[n] = sums[n] + i
      n = n + i
   end
end

-- Check if amicable
sum = 0
for i = 2, limit do
   if sums[i] < i then
      if sums[sums[i]] == i then
         sum = sum + i + sums[i]
      end
   end
end

print(sum)
