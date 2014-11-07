#!/usr/bin/env lua

print("Project Euler - Problem 9:")
print("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n")

a = 1
product = 0
while true do
   a = a + 1
   b = a
   while true do
      b = b + 1
      c = math.sqrt((a * a) + (b * b))
      if a + b + c > 1000 then
         break
      end
      if c == math.floor((c)) then
         --print(a.." "..b.." "..c) -- DEBUG
         if a + b + c == 1000 then
            product = a * b * c
         end
         if (product > 0) then
            break
         end
      end
   end
   if (product > 0) then
      break
   end
end

print("Product: "..product)
