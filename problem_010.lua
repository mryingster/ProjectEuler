#!/usr/bin/env lua

function isPrime (number)
   limit = math.floor(math.sqrt(number))
   for index = 3, limit , 2 do
      if (number % index == 0) then
         return false
      end
   end
   return true
end

print("Project Euler - Problem 10:\n")
print("Find the sum of all the primes below two million.\n\n")

sum = 2 --Starting off with first prime accounted for
for number=3, 2000000, 2 do
   if (isPrime(number)) then
      sum = sum + number
   end
end

print("Sum of primes: "..sum.."\n")
