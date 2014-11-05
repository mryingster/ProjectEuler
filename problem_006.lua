#!/usr/bin/env lua

print("Project Euler - Problem 6:")
print("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n")

sumsquares = 0
squaresums = 0

for number=1 , 100 , 1 do
   squaresums = squaresums + number
end

squaresums = squaresums * squaresums

for number=1 , 100 , 1 do
   sumsquares = sumsquares + (number * number)
end

result = squaresums-sumsquares

print("Difference: "..result)
