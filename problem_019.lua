#!/usr/bin/env lua

print("Project Euler - Problem 19:")
print("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n")

-- January 1 1901 was a Tuesday

date = 1
day = 3
month = 1
year = 1901
count = 0

monthLength = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

while year < 2001 do
   -- Check for Sunday being first of Month
   if day == 1 and date == 1 then
      count = count + 1
   end

   -- Increment everything
   date = date + 1
   day = day + 1

   -- Wrap week
   if day > 7 then day = 1 end

   -- Wrap Month
   length = monthLength[month]
   -- Leap Year
   if month == 2 then
      if year % 4 == 0 then
         length = length + 1
      end
   end
   if date > length then
      date = 1
      month = month + 1
   end

   -- Wrap Year
   if month > 12 then
      month = 1
      year = year + 1
   end
end

print(count)

