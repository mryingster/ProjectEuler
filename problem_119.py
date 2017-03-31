#!/usr/bin/python

def GetDigitSum(Input):
    Result=0
    for i in range(len(str(Input))):
        Result+=int(str(Input)[i])
    return Result

Answers=[]

for n in range(2,70):
    for e in range(2,40):
        Potential=n**e
        if n==GetDigitSum(Potential):
            #print n, e, Potential
            Answers.append(int(Potential))

Answers.sort(key=int)

print "30th Power Digit:", str(Answers[30-1])
# 248155780267521, 0m0.310s
