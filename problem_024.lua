#!/usr/bin/env lua

print("Project Euler - Problem 24:")
print("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n")

function nextPerm(a)
   -- Find the largest index k such that a[k] < a[k + 1]
   k = 0
   for i=1, table.maxn(a)-1 do
      if a[i] < a[i+1] then
         k = i
      end
   end

   -- If we reached end, we can't permute!
   if k == 0 then
      return a
   end

   -- Find the largest index l greater than k such that a[k] < a[l]
   l = 0
   for i=k, table.maxn(a) do
      if a[k] < a[i] then
         l = i
      end
   end

   -- Swap the value of a[k] with that of a[l]
   t = a[k]
   a[k] = a[l]
   a[l] = t

   -- Reverse the sequence from a[k + 1] up to and including the final element a[n]
   if k < table.maxn(a)-1 then
      r = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
      j = table.maxn(a)
      for i=(k+1), table.maxn(a) do
         r[j] = a[i]
         j = j - 1
      end
      for i=k+1, table.maxn(a) do
         a[i] = r[i]
      end
   end

   return a
end

-- Numbers to permute
array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

-- Permute 1 million times
for i=1, 1000000 do
   array = nextPerm(array)
end

-- Print
for i=1, table.maxn(array) do
   io.write(array[i])
end
print("")
