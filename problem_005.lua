#!/usr/bin/env lua

print("Project Euler - Problem 5:")
print("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n")

for number = 1000, 500000000, 20 do
   candidate = 1
   for divisor = 2 , 20 , 1 do
      if not ( number % divisor == 0 ) then
         candidate = 0
         break
      end
   end
   if ( candidate == 1 ) then
      print("Smallest number: "..number)
      break
   end
end
