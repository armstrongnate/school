import sys, os
from Tables import *
from CodeWriter import *

symbols = "_.$:"

def isSymbol(string):
    '''Determine if a string is a symbol.'''
    
    if len(string) < 1:
        return False

    if string[0].isdigit():
        return False

    for char in string:
        if char not in symbols:
            if not char.isalnum():
                return False
    return True

def isConstant(string):
    '''Determine if a string is a constant.'''

    if len(string) < 1 or len(string) > 5:
        return False

    if int(string) < 0 or int(string) > 32767:
        return False

    return True

def fail(message, sourceLine, sourceInputLine):
    '''Raises an exception for debugging.'''

    sys.stderr.write("Error: %s. Source Line: %s. Source Input Line: %s." % \
                    (message, sourceLine, sourceInputLine))
    sys.exit()

def parseLine(line, lineNumber):
    parsedLine = line.strip()
    
    if (line.find('//') != -1):
        parsedLine = line[:line.find('//')]
    parsedLine.strip()

    if len(parsedLine) < 1:
        return None

    parsedLine = parsedLine.split()
    cmd = parsedLine[0]

    if commandsTable.get(cmd) == None:
        fail("Not a valid command", line, lineNumber)

    argumentCount = commandsTable[cmd]
    arguments = []

    for i in range(argumentCount):
        if i >= len(parsedLine)-1:
            fail("Command expected argumentCount", line, lineNumber)
            
        argument = parsedLine[i+1]
        if i == 0:
            if cmd == 'push' or cmd == 'pop':
                if segmentsTable.get(argument) == None:
                    fail("Argument 1 expected valid segment, got %s" % argument,
                         line, lineNumber)
            else:
                if not isSymbol(argument):
                    fail("Argument 1 expected valid symbol, got %s" % type(argument),
                         line, lineNumber)
        elif i == 1:
            if not isConstant(argument):
                fail("Argument 2 expected constant, got %s" % type(argument),
                     line, lineNumber)

    return tuple(parsedLine)

def parseFile(filename):
    fin = open(filename)
    parsedLines = []
    count = 0
    
    for line in fin:
        parsedLine = parseLine(line, count)
        if parsedLine:
            parsedLines.append(parsedLine)
            count += 1
    fin.close()

    return parsedLines

def processFile(codeWriter, filename, instructionList):
    codeWriter.setFileName(filename[:filename.find('.vm')])

    for instruction in instructionList:
        if instruction[0] == 'push' or instruction[0] == 'pop':
            codeWriter.writePushPop(instruction[0], instruction[1], int(instruction[2]))
        elif len(instruction) == 1:
            codeWriter.writeArithmetic(instruction[0])

def main():
    if len(sys.argv) != 2:
        sys.stderr("Input not valid.")
        sys.exit()

    inputPath = os.path.abspath(sys.argv[1].strip())
    outputPath = ""
    directory = False
    filepathList = []

    if inputPath.endswith('.vm'):
        outputPath = inputPath[:inputPath.find('.vm')] + '.asm'
    else:
        directory = True
        outputPath = os.path.join(inputPath, os.path.basename(inputPath)) + '.asm'

    if not directory:
        if os.path.isfile(inputPath):
            filepathList.append(inputPath)
        else:
            sys.stderr.write("File does not exist.")
            sys.exit()
    else:
        if os.path.isdir(inputPath):
            filepathList = os.listdir(inputPath)
            newList = []

            for filepath in filepathList:
                if filepath.endswith('.vm'):
                    filePath = os.path.join(inputPath, filepath)
                    if os.path.isfile(filePath):
                        newList.append(filePath)
            filepathList = newList
        else:
            sys.stderr.write("Directory not valid.")
            sys.exit()

    parsedFileList = []
    outfile = open(outputPath, 'w')
    codeWriter = CodeWriter(outfile)

    for filepath in filepathList:
        filename = os.path.basename(filepath)
        print "Processing %s." % os.path.basename(filename)
        parsedList = parseFile(filepath)
        parsedFileList.append( (filepath, parsedList) )

        processFile(codeWriter, filename, parsedList)

    codeWriter.writePost()
    outfile.close()
        


















            
main()
