#!/usr/bin/env lua

print("Project Euler - Problem 14:")
print("Which starting number, under one million, produces the longest chain by following the rules below?\n")
print("if n is even, n/2\nif n is odd, 3n+1\n")

limit = 1000000
history = {}
max = {0, 0}

for i = 1, limit, 1 do
   n = i
   count = 0

   -- Main loop to process number
   while (n ~= 1) do
      if (n % 2 == 0) then
         n = n / 2
      else
         n = 3 * n + 1
      end
      count = count + 1

      -- Refer to history if we have number less than i
      if (n < i) then
         count = count + history[n]
         n = 1
      end
   end
   history[i] = count

   -- Keep track of max result
   if (count > max[1]) then
      max[1] = count
      max[2] = i
   end
end

print(max[2])
