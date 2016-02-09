#!/usr/bin/python
import csv, os, sys, glob, datetime

#### CSV Operations ####
def verifyCSVFileExists(csvfilename, fields):
    try:
        with open(csvfilename): pass
    except IOError:
        print "Creating new file,", csvfilename
        with open(csvfilename, 'w') as csvfile:
            csvwriter = csv.DictWriter(csvfile, delimiter=',', fieldnames=fields)
            csvwriter.writerow(dict((fn,fn) for fn in fields))

def readCSV(csvfilename):
    dictarray = []
    with open(csvfilename, 'rb') as csvfile:
        csvdata = csv.DictReader(csvfile, delimiter=',', quotechar='"')
        for row in csvdata:
            dictarray.append(row)
        return dictarray

def genCSVRowFromArray(array):
    output=""
    for i in array:
        output=output+str(i)
        if array.index(i) == len(array)-1:
            return output
        output = output+","

def genCSVRowFromDict(dict, fields):
    output=""
    for i in fields:
        if i in dict:
            output=output+str(dict[i])
        if fields.index(i) == len(fields)-1:
            return output
        output = output+","
    return output

def writeCSV(csvfilename, dictarray, fields):
    with open(csvfilename, 'w') as csvfile:
        csvfile.write(str(genCSVRowFromArray(fields))+"\n")
        for row in dictarray:
            csvfile.write(str(genCSVRowFromDict(row, fields))+"\n")
        csvfile.close()
        return

#### Array Manipulations ####
def resortArray(dictArray):
    resortedArray = sorted(dictArray, key=lambda row: row["Problem"])
    return resortedArray

#### MarkDown Operations ####

def writeToFile(file, buffer, append=False):
    if append == False:
        open(file, "w").write(buffer)
    else:
        open(file, "a").write(buffer)

def MDfromArray(array, len):
    string = "|"
    for e in array:
        string += " {0:{1}} |".format(e, len)
    return string+"\n"

def genMarkdownHeader(fields, MDFieldLen = 14):
    buffer = ""

    # Header
    buffer += MDfromArray(fields, MDFieldLen)

    tempArray = []
    for f in fields:
        tempArray.append("-"*MDFieldLen)
    buffer += MDfromArray(tempArray, MDFieldLen)
    return buffer

def genMarkdownRow(fields, data, MDFieldLen = 14):
    tempArray = []
    for f in fields:
        if f in data:
            tempArray.append(data[f])
        else:
            tempArray.append("")
    return MDfromArray(tempArray, MDFieldLen)

def saveMarkDown(markDownFile, fieldsArray, dictArray):
    writeToFile(markDownFile, genMarkdownHeader(fieldsArray))
    for results in dictArray:
        writeToFile(markDownFile, genMarkdownRow(fieldsArray, results), True)

#### Timing Operations ####

def timeSolution(path):
    from subprocess import call
    start = datetime.datetime.now()
    call(path)
    end =  datetime.datetime.now()
    return str(end-start)

#### Compile Operations ####

def compileC(path):
    from subprocess import call
    output = path[:-2]+"_c"
    call(["gcc", "-std=c99", "-o", output, path, "ceuler.c", "-Wall", "-lm"])
    return output

def compileCPP(path):
    from subprocess import call
    output = path[:-4]+"_cpp"
    call(["g++", "-std=c++0x", "-o", output, path, "ceuler.c", "-Wall", "-lm"])
    return output

def compileSwift(path):
    from subprocess import call
    output = path[:-6]+"_swift"
    call(["swiftc",  path, "-o", output])
    return output

def compileRust(path):
    from subprocess import call
    output = path[:-3]+"_rs"
    call(["rustc", "-o", output, path])
    return output

#### Main Function ####

def main(csvFile, markDownFile, dictArray, fieldsArray, timeRange):
    for problem in range(timeRange[0], timeRange[1]):
        number = "%03d" % problem

        # See if we have an entry for this problem yet
        index = -1
        for i in dictArray:
            if i["Problem"] == number:
                index = dictArray.index(i)
                break

        # If not, make a new row
        if index == -1:
            dictArray.append({"Problem":number})
            index = len(dictArray) - 1

        for f in glob.glob('./problem_*'+number+'.*'):
            ext = f.split(".")[-1].lower()

            # Time script based solutions
            if ext in scriptDict:
                dictArray[index].update({scriptDict[ext]:timeSolution(f)})

            # Time compiled solutions
            if ext == "c":
                executable = compileC(f)
                if os.path.exists(executable):
                    dictArray[index].update({"C/C++":timeSolution(executable)})
            if ext == "rs":
                executable = compileRust(f)
                if os.path.exists(executable):
                    dictArray[index].update({"Rust":timeSolution(executable)})
            if ext == "cpp":
                executable = compileCPP(f)
                if os.path.exists(executable):
                    dictArray[index].update({"C/C++":timeSolution(executable)})
            if ext == "swift":
                import platform
                if platform.system() == "Darwin":
                    executable = compileSwift(f)
                    if os.path.exists(executable):
                        dictArray[index].update({"swift":timeSolution(executable)})

            # Update CSV File
            dictArray = resortArray(dictArray)
            writeCSV(csvFile, dictArray, fieldsArray)

    # Write Mark Down File
    saveMarkDown(markDownFile, fieldsArray, dictArray)


# Create file(s)
csvFile = "times.csv"
markDownFile = "times.md"
fieldsArray = ["Problem", "Python", "C/C++", "Perl", "Lua", "Swift", "Rust"]

verifyCSVFileExists(csvFile, fieldsArray)
dictArray = readCSV(csvFile)

# Write backup file before making changes
writeCSV(csvFile+"~", dictArray, fieldsArray)

scriptDict = {"py":"Python","lua":"Lua","pl":"Perl"}
compileDict = {"c":"C", "rs":"Rust", "swift":"Swift", "cpp":"C"}

# Handle Input Params
timeRange = [1, 101]
if len(sys.argv) == 2 and sys.argv[1].isdigit():
    timeRange = [int(sys.argv[1]), int(sys.argv[1])+1]
if len(sys.argv) == 3 and sys.argv[1].isdigit() and sys.argv[2].isdigit():
    timeRange = [int(sys.argv[1]), int(sys.argv[2])]

main(csvFile, markDownFile, dictArray, fieldsArray, timeRange)

