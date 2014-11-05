#!/usr/bin/env lua

print("Project Euler - Problem 1")
print("Find the sum of all the multiples of 3 or 5 below 1000.\n")

number = 1
sum = 0

while (number < 1000) do
   if (number % 3 == 0) then
      sum = sum + number
   else
      if (number % 5 == 0) then
         sum = sum + number
      end
   end
   number = number + 1
end

print("Sum: "..sum)
