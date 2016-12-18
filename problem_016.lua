#!/usr/bin/env lua

print("Project Euler - Problem 16:")
print("What is the sum of the digits of the number 2^1000\n")

function printArray(a)
   i = 1
   while a[i] do
      io.write(a[i].." ")
      i = i + 1
   end
   print("")
end

array = {}
array[1] = 2

for n=2, 1000 do
   -- Multiply each cell by 2
   i = 1
   while array[i] do
      array[i] = array[i] * 2
      i = i + 1
   end

   -- Carry over digits
   i = 1
   while array[i] do
      while array[i] > 9 do
         array[i] = array[i] - 10
         -- Create new cell if we run out of space
         if not array[i+1] then
            array[i+1] = 0
         end
         array[i+1] = array[i+1] + 1
      end
      i = i + 1
   end

   -- Debug
   -- printArray(array)
end

-- Sum it up
sum = 0
i = 1
while array[i] do
   sum = sum + array[i]
   i = i + 1
end


-- Print sum
print(sum)
