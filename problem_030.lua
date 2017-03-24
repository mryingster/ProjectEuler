#!/usr/bin/env lua

print("Project Euler - Problem 1")
print("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n")

-- pre-calculate fifth powers
fifth = {}
for n=0, 9 do
   fifth[n] = n * n * n * n * n
end

-- Isolate digits and sum powers
function getFifthPowerSum(n)
   digitSum = 0

   while n > 0 do
      digitSum = digitSum + fifth[n % 10]
      n = math.floor(n / 10)
   end
   return digitSum
end

-- Check each number through limit
-- (Tipping point where 5th powers are no longer big enough to add to number)
limit = fifth[9] * 6
sum = 0
for n=2, limit do
   if getFifthPowerSum(n) == n then
      sum = sum + n
   end
end

print(sum)
