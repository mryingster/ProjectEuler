#!/usr/bin/env lua

print("Project Euler - Problem 12:")
print("What is the value of the first triangle number to have over five hundred divisors?\n")

function getDivisors(n)
   divisors = 1
   divisor = 2
   while n > 1 do
      count = 1
      while n % divisor ~= 0 do
         divisor = divisor + 1
      end

      while n % divisor == 0 do
         n = n / divisor
         count = count + 1
      end
      divisors = divisors * count
   end
   return divisors
end

t = 1
answer = 0
for n=2 , 100000 , 1 do
   t = t + n
   b = a
   d = getDivisors(t)
   if d > 500 then
      answer = t
      break
   end
end

print(answer)
