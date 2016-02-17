#!/usr/bin/python
import csv, os, sys, glob, datetime, platform

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
    if not os.path.exists(path): return ""
    print ("Testing: %s." % path)

    from subprocess import call
    start = datetime.datetime.now()
    try:
        call(path)
    except:
        print("Error encountered while testing %s." % path)
        return ""
    end =  datetime.datetime.now()
    return str(end-start)

#### Compile Operations ####

def compile(path, ext):
    print("Compiling %s." % path)

    if ext == "c":
        output = path[:-2]+"_c"
        compileCommand = ["gcc", "-std=c99", "-o", output, path, "ceuler.c", "-Wall", "-lm"]
    if ext == "cpp":
        output = path[:-4]+"_cpp"
        compileCommand = ["g++", "-std=c++0x", "-o", output, path, "ceuler.c", "-Wall", "-lm"]
    if ext == "swift":
        output = path[:-6]+"_swift"
        compileCommand = ["swiftc",  path, "-o", output]
    if ext == "rs":
        output = path[:-3]+"_rs"
        compileCommand = ["rustc", "-o", output, path]

    from subprocess import call
    try:
        call(compileCommand)
    except:
        print("Unable to compile %s." % path)
        return ""
    return output

#### Main Function ####

def main(csvFile, markDownFile, dictArray, fieldsArray, params):
    scriptDict = {"py":"Python","lua":"Lua","pl":"Perl"}
    compileDict = {"c":"C/C++", "rs":"Rust", "swift":"Swift", "cpp":"C/C++"}

    for problem in range(params["range"][0], params["range"][1]):
        if problem < 1: continue
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
                if params["retest"] == True or scriptDict[ext] not in dictArray[index] or dictArray[index][scriptDict[ext]] == "":
                    dictArray[index].update({scriptDict[ext]:timeSolution(f)})

            # Time compiled solutions
            if ext in compileDict:
                if params["retest"] == True or compileDict[ext] not in dictArray[index] or dictArray[index][compileDict[ext]] == "":
                    if ext == "swift" and platform.system() != "Darwin": continue
                    executable = compile(f, ext)
                    if executable == "": continue
                    dictArray[index].update({compileDict[ext]:timeSolution(executable)})

            # Update CSV File
            dictArray = resortArray(dictArray)
            writeCSV(csvFile, dictArray, fieldsArray)

    # Write Mark Down File
    saveMarkDown(markDownFile, fieldsArray, dictArray)


# Create file(s)
csvFile = "times.csv"
markDownFile = "times.md"
fieldsArray = ["Problem", "C/C++", "Swift", "Python", "Perl", "Lua", "Rust"]

verifyCSVFileExists(csvFile, fieldsArray)
dictArray = readCSV(csvFile)

# Write backup file before making changes
writeCSV(csvFile+"~", dictArray, fieldsArray)

# Handle Input Params
args = sys.argv

params = {"retest":False}
if "-r" in args:
    params.update({"retest":True})
    args.pop(args.index("-r"))

params.update({"range":[1, 101]})
if len(args) == 2 and args[1].isdigit():
    params.update({"range":[int(args[1]), int(args[1])+1]})
if len(args) == 3 and args[1].isdigit() and args[2].isdigit():
    params.update({"range":[int(args[1]), int(args[2])+1]})

main(csvFile, markDownFile, dictArray, fieldsArray, params)
