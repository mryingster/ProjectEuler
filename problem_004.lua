#!/usr/bin/env lua

print("Project Euler - Problem 4:")
print("Find the largest palindrome made from the product of two 3-digit numbers.\n")

result = 0

for a = 999, 100, -1 do
   for b = a, 100, -1 do
      product = a * b
      tcudorp = 0
      while (product > 0) do
         tcudorp = math.floor(tcudorp * 10)
         tcudorp = tcudorp + (product % 10)
         product = math.floor(product / 10)
      end
      product = a * b
      --print (product.." "..tcudorp) --DEBUG
      if ( product == tcudorp ) then
         if result < product then
            result = product
         end
      end
   end
end

print("Largest product: "..result)
