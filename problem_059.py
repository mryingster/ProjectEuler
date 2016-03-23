#!/usr/bin/env python
import re

print("Project Euler - Problem 42:")
print("Decrypt the message and find the sum of the ASCII values in the original text.\n")

def isPlainASCII(c):
    if c > ord("z"): return False
    if c < ord(" "): return False
    return True

def seemsLegit(text):
    text = text.split(" ")
    for word in text:
        if len(word) > 15:
            return False
    return True

def findCipher(inBuffer):
    # Cipher is 3 letters, so brute force all combinations
    for A in range(ord('a'), ord('z')):
        for B in range(ord('a'), ord('z')):
            for C in range(ord('a'), ord('z')):
                cipher = [A, B, C]
                outBuffer = ""
                bufferSum = 0
                solution = True
                # Take 3 letters at a time
                for i in range(0, len(inBuffer), 3):
                    # For each letter, decipher, and see if its plain ascii
                    for j in range(0, 3):
                        if i+j < len(inBuffer):
                            char = int(inBuffer[i+j])^cipher[j]
                            if isPlainASCII(char) == False:
                                solution = False
                                break
                            outBuffer += chr(char)
                            bufferSum += char
                    if solution == False: break

                # If it is plain ascii, take whole paragraph and see if it looks ok-ish
                if solution == True and seemsLegit(outBuffer):
                    return chr(A)+chr(B)+chr(C), outBuffer, bufferSum

# Read file in, and put into a list
ReadFile = open("problem_059.txt")
inBuffer = ReadFile.readline()
inBuffer = inBuffer.split(",")

# Get the answer
cipher, text, asciiSum = findCipher(inBuffer)

print("Cipher: %s" % cipher)
print(text)
print("")
print(asciiSum)
