#!/usr/bin/env lua

print("Project Euler - Problem 28:")
print("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n")

limit = 1001 * 1001
n = 1
sum = 1
step = 2
side = 0

while n < limit do
   n = n + step
   sum = sum + n
   side = side + 1
   if side % 4 == 0 then
      step = step + 2
   end
end

print(sum)
