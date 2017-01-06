#!/usr/bin/env lua

print("Project Euler: 22")
print("Sort 5000 names and calculate the sum of their name scores.\n")

debug = false

-- Return partial score for name
function score(name)
   namescore = 0
   for i=1, string.len(name) do
      namescore = namescore + string.byte(name, i) - string.byte('A') + 1
   end
   return namescore
end

-- Read in file
filename = "problem_022.txt"
local file = io.open(filename, "rb")
data = file:read "*a"

-- Separate names to array
names = {}
index = 0
for name in string.gmatch(data, "%w+") do
   index = index + 1
   names[index] = name
end

if debug == true then print("Read in "..index.." names.") end

-- Sort the array
table.sort(names, function (a, b) return string.lower(a) < string.lower(b) end)

if debug == true then print("Sorted names. First name: "..names[1].."; Last name: "..names[index]) end

-- Score Names and Tally
total = 0
for i=1, index do
   namescore = i * score(names[i])
   total = total + namescore
end

print(total)
