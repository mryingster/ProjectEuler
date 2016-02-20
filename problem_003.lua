#!/usr/bin/env lua

print("Project Euler - Problem 3:")
print("What is the largest prime factor of the number 600851475143 ?\n")

number = 600851475143
lastFactor = 0

for  i = 2, 10000, 1 do
   if ( number % i == 0 ) then
      number = number / i
      lastFactor = i
      i = 2
   end
end

print("Largest factor found: "..lastFactor)
