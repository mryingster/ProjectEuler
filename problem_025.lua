#!/usr/bin/env lua

print("Project Euler - Problem 25")
print("What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n")

number = 1
numTmp = 0
numPre = 0

count = 1
digits = 6

while (digits < 1000) do
   numTmp = number
   number = number + numPre
   numPre = numTmp

   while (number > 1000000) do
      number = number / 10
      numPre = numPre / 10
      digits = digits + 1
   end

   --print(number)
   count = count + 1
end

print(count)
