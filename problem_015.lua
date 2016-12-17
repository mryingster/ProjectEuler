#!/usr/bin/env lua

print("Project Euler - Problem 15:")
print("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n")

function initArray(value, length)
   a = {}
   for i=1, length do
      a[i] = value
   end
   return a
end

function printArray(a)
   i = 1
   while a[i] do
      io.write(a[i].." ")
      i = i + 1
   end
   print("")
end

array = initArray(0, 41)
array[1] = 1

-- Compute Pascal's triangle in place
for n=1, 40 do
   previousValue = 1
   for i=2, 40 do
      currentValue = array[i]
      array[i] = array[i] + previousValue
      previousValue = currentValue
   end
   -- Debug
   -- printArray(array)
end

-- Print the middle value of the final line
print(array[21])
