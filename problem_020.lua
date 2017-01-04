#!/usr/bin/env lua

print("Project Euler - Problem 20:")
print("Find the sum of the digits in the number 100!\n")

number = {1}
debug = false

function printNumber(n)
   for i=table.maxn(n), 1, -1 do
      io.write(n[i])
   end
   print("")
end

for n=100, 1, -1 do
   -- Multiply each digit by next 'n'
   for i=1, table.maxn(number) do
      number[i] = number[i] * n
   end

   -- Perform carryover arithmatic
   i = 1
   while i <= table.maxn(number) do
      -- Expand array if we need to
      if i == table.maxn(number) and number[i] > 9 then
         number[i+1] = 0
      end

      -- Carry over. Each cell should have single digit
      while number[i] > 9 do
         number[i+1] = number[i+1] + math.floor(number[i]/10)
         number[i] = number[i] % 10
      end
      i = i + 1
   end

   if debug == true then
      printNumber(number)
   end
end

-- Sum it up
total = 0
for i=1, table.maxn(number) do
   total = total + number[i]
end

print(total)
