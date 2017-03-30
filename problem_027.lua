#!/usr/bin/env lua

print("Project Euler - Problem 27:")
print("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n")

function isPrime (number)
   if number < 2 then return false end
   limit = math.floor(math.sqrt(number))
   for index = 3, limit , 2 do
      if (number % index == 0) then
         return false
      end
   end
   return true
end

max_primes = 0
max_product = 0

for a=-1000, 1000 do
   for b=-1000, 1000 do
      n = 0
      repeat
         quadratic = (n * n) + (a * n) + b
         n = n + 1
      until isPrime(quadratic) == false

      if n > max_primes then
         max_primes = n
         max_product = a * b
      end
   end
end

print(max_product)
