import sys, os
from Tables import *
from CommandStrings import *

class CodeWriter:
    def __init__(self, filestream):
        self.__filestream = filestream
        self.__filename = None

        #Add common routines to the top of the code

        self.__eqCount = 0
        self.__gtCount = 0
        self.__ltCount = 0

        self.__commandDict = {
            "pop" : popInstance,
            "push": pushInstance,
            "add" : addInstance,
            "sub" : subInstance,
            "neg" : negInstance,
            "and" : andInstance,
            "or"  : orInstance,
            "not" : notInstance,
            "eq"  : eqInstance,
            "lt"  : ltInstance,
            "gt"  : gtInstance,
            "static" : staticPop,
            "temp" : staticPop,
            "pointer" : staticPop,
            "isMem" : locationIsMemory,
            "inMem" : locationInMemory }

    def getFilestream(self):
        return self.__filestream
    Filestream = property(getFilestream)

    def setFileName(self, filename):
        self.__filename = filename

    def writePushPop(self, command, segment, index):
        '''Takes argument list of string, string, int.'''

        #print >>self.__filestream, "//%s %s %s" % (command, segment, index)

        if command == "push":
            if segment == "constant":
                print >>self.__filestream, pushConstant % index
                
            elif segment == "static":
                segment = "%s.%s" % (self.__filename, index)
                print >>self.__filestream, locationInMemory % segment
                print >>self.__filestream, pushInstance
                
            elif segment == "pointer":
                ptr = ""
                if index == 0:
                    ptr = "R3"
                elif index == 1:
                    ptr = "R4"
                else:
                    sys.stderr.write("Error: pointer offset not valid, got %s" % index)
                print >>self.__filestream, locationIsMemory % ptr
                print >>self.__filestream, pushFromInstance % index
                
            elif segment == "temp":
                print index
                print >>self.__filestream, locationIsMemory % (index + 5)
                print >>self.__filestream, pushFromInstance % (index + 5)
                print >>self.__filestream, pushInstance

            elif segment == "local":
                print >>self.__filestream, locationInMemory % "LCL"
                print >>self.__filestream, pushFromInstance % index
                print >>self.__filestream, pushInstance

            elif segment == "argument":
                print >>self.__filestream, locationInMemory % "ARG"
                print >>self.__filestream, pushFromInstance % index
                print >>self.__filestream, pushInstance

            elif segment == "this":
                print >>self.__filestream, locationInMemory % "THIS"
                print >>self.__filestream, pushFromInstance % index
                print >>self.__filestream, pushInstance

            elif segment == "that":
                print >>self.__filestream, locationInMemory % "THAT"
                print >>self.__filestream, pushFromInstance % index
                print >>self.__filestream, pushInstance
            
        elif command == "pop":
            if segment == "static":
                index = "%s.%s" % (self.__filename, index)
                print >>self.__filestream, popInstance
                print >>self.__filestream, locationSetMemory % index

            elif segment == "pointer":
                ptr = ""
                if index == 0:
                    ptr = "R3"
                elif index == 1:
                    ptr = "R4"
                else:
                    sys.stderr.write("Error: pointer offset not valid, got %s" % index)
                print >>self.__filestream, locationIsMemory % ptr
                print >>self.__filestream, popCommand

            elif segment == "temp":
                print >>self.__filestream, locationIsMemory % ("R%s" %(index + 5))
                print >>self.__filestream, locationSetD % ("R%s" % (index + 5))
                print >>self.__filestream, popCommand
                
            elif segment == "local":
                print >>self.__filestream, locationInMemory % "LCL"
                print >>self.__filestream, locationSetD % index
                print >>self.__filestream, popCommand
            elif segment == "argument":
                print >>self.__filestream, locationInMemory % "ARG"
                print >>self.__filestream, locationSetD % index
                print >>self.__filestream, popCommand
            elif segment == "this":
                print >>self.__filestream, locationInMemory % "THIS"
                print >>self.__filestream, locationSetD % index
                print >>self.__filestream, popCommand
            elif segment == "that":
                print >>self.__filestream, locationInMemory % "THAT"
                print >>self.__filestream, locationSetD % index
                print >>self.__filestream, popCommand

    def writePost(self):
        print >>self.__filestream, haltInstance
        
        if self.__eqCount > 0:
            print >>self.__filestream, eqInit
        if self.__ltCount > 0:
            print >>self.__filestream, ltInit
        if self.__gtCount > 0:
            print >>self.__filestream, gtInit

    def writeArithmetic(self, command):
        #print >>self.__filestream, "\t //%s" % command

        if command == "eq":
            print >>self.__filestream, self.__commandDict[command] % (self.__eqCount, self.__eqCount)
            self.__eqCount += 1
        elif command == "gt":
            print >>self.__filestream, self.__commandDict[command] % (self.__gtCount, self.__gtCount)
            self.__gtCount += 1
        elif command == "lt":
            print >>self.__filestream, self.__commandDict[command] % (self.__ltCount, self.__ltCount)
            self.__ltCount += 1
        elif command == "add":
            print >>self.__filestream, addInstance
        elif command == "sub":
            print >>self.__filestream, subInstance
