#!/usr/bin/env lua

print("Project Euler - Problem 7:")
print("What is the 10,001st prime number?\n")

function isPrime (number)
   limit = math.floor(math.sqrt(number))
   for index = 3, limit , 2 do
      if (number % index == 0) then
         return false
      end
   end
   return true
end

prime=3
number=3
count=2

while (count < 10001) do
   number = number + 2
   if isPrime(number) == true then
      prime = number
      count = count + 1
   end
end

print("10,001st prime: "..prime)
