import sys, os
from CommandStrings import *

class CodeWriter:
    def __init__(self, filestream):
        self.__filestream = filestream
        self.__filename = None

        self.__eqCount = 0
        self.__gtCount = 0
        self.__ltCount = 0

        self.__segmentDict = {
            "local" : "LCL",
            "argument" : "ARG",
            "this" : "THIS",
            "that" : "THAT"}

    def getFilestream(self):
        return self.__filestream
    Filestream = property(getFilestream)

    def setFileName(self, filename):
        self.__filename = filename
    Filename = property(None, setFileName)

    def write(self, string):
        print >>self.__filestream, string

    def writePushPop(self, command, segment, index):
        print >>self.__filestream, "\t//%s %s %s" % (command, segment, index)

        if segment in self.__segmentDict:
            segment = self.__segmentDict[segment]

        if command == "push":
            if segment == "constant":
                self.write(pushConstant % index)
            elif segment == "static":
                address = "%s.%s" % (self.__filename, index)
                self.write(pushTemp % address)
            elif segment == "pointer":
                address = index
                if index == 0:
                    address = "R3"
                if index == 1:
                    address = "R4"
                self.write(pushTemp % address)
            elif segment == "temp":
                address = "R%s" % (index + 5)
                self.write(pushTemp % address)
            else:
                self.write(pushLocal % (index, segment))
        elif command == "pop":
            if segment == "static":
                address = "%s.%s" % (self.__filename, index)
                self.write(popAtAddress % address)
            elif segment == "pointer":
                address = index
                if index == 0:
                    address = "R3"
                if index == 1:
                    address = "R4"
                self.write(popAtAddress % address)
            elif segment == "temp":
                address = "R%s" % (index + 5)
                self.write(popTemp % (address))
            else:
                self.write(popLocal % (index, segment))
                

    def writeArithmetic(self, command):
        if command == "add":
            print >>self.__filestream, addInstance
        if command == "sub":
            print >>self.__filestream, subInstance

    def writePost(self):
        return



            
