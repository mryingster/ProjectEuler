#!/usr/bin/env lua

print("Project Euler - Problem 23")
print("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n")

function divSum(n)
   sum = 0
   for d = 1, n/2+1, 1 do
      if (n % d == 0) then
         sum = sum + d
      end
   end
   return sum
end

limit = 28123

abundant = {}
index = 0
for n = 12, limit, 1 do
   if divSum(n) > n then
      abundant[index] = n
      index = index + 1
   end
end

sums = {}
for a = 0, index-1, 1 do
   for b = a, index-1, 1 do
      n = abundant[a] + abundant[b]
      if n > limit then
         break
      end
      sums[n] = 1
   end
end

sum = 0
for i = 0, limit, 1 do
   if sums[i] == nil then
      sum = sum + i
   end
end

print(sum)
