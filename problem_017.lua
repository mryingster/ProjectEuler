#!/usr/bin/env lua

print("Project Euler - Problem 17:")
print("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?\n")

function length(n)
   if     n < 1     then return 0
   elseif n == 1    then return 3 -- one
   elseif n == 2    then return 3 -- two
   elseif n == 3    then return 5 -- three
   elseif n == 4    then return 4 -- four
   elseif n == 5    then return 4 -- five
   elseif n == 6    then return 3 -- six
   elseif n == 7    then return 5 -- seven
   elseif n == 8    then return 5 -- eight
   elseif n == 9    then return 4 -- nine
   elseif n == 10   then return 3 -- ten
   elseif n == 11   then return 6 -- eleven
   elseif n == 12   then return 6 -- twelve
   elseif n == 13   then return 8 -- thirteen
   elseif n == 14   then return 8 -- fourteen
   elseif n == 15   then return 7 -- fifteen
   elseif n == 16   then return 7 -- sixteen
   elseif n == 17   then return 9 -- seventeen
   elseif n == 18   then return 8 -- eighteen
   elseif n == 19   then return 8 -- nineteen
   elseif n < 30    then return 6 -- twenty
   elseif n < 40    then return 6 -- thirty
   elseif n < 50    then return 5 -- forty
   elseif n < 60    then return 5 -- fifty
   elseif n < 70    then return 5 -- sixty
   elseif n < 80    then return 7 -- seventy
   elseif n < 90    then return 6 -- eighty
   elseif n < 100   then return 6 -- ninety
   elseif n == 100  then return 7 -- hundred
   elseif n == 1000 then return 8 -- thousand
   else                  return 0
   end
end

total = 0
for n = 1, 1000 do
   characters = 0

   if (n >= 1000) then
      characters = characters + length(math.floor(n / 1000))
      characters = characters + length(1000)
      n = n % 100
   end

   if (n >= 100) then
      characters = characters + length(math.floor(n / 100))
      characters = characters + length(100)
      n = n % 100

      -- Add silly English "and" if we aren't at an even hundred
      if n > 0 then
         characters = characters + 3
      end
   end

   if (n > 20) then
      characters = characters + length(n)
      n = n % 10
   end

   characters = characters + length(n)
   total = total + characters
end

print(total)
