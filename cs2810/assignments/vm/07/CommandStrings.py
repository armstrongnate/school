#Define all command strings

eqInit = \
"""
    //Reference to EQ command
(_EQ)
@R15
M=D

A=D
D=M
D=D-M
@_EQ_TRUE
D;JEQ
    //Is not equal, push false
@0
D=A
@SP
AM=M+1
A=A-1
M=D
@_EQ_END
0;JMP
(_EQ_TRUE)
    //Is equal, push true
@-1
D=A
@SP
AM=M+1
A=A-1
M=D
(_EQ_END)
@R15
0;JMP
    //End EQ
"""

ltInit = \
"""
    //Reference to LT command
(_LT)
@R15
M=D

A=D
D=M
D=D-M
@_LT_TRUE
D;JLT
    //Is not less than, push false
@0
D=A
@SP
AM=M+1
A=A-1
M=D
@_LT_END
0;JMP
(_LT_TRUE)
    //Is less than, push true
@-1
D=A
@SP
AM=M+1
A=A-1
M=D
(_LT_END)
@R15
0;JMP
    //End LT
"""

gtInit = \
"""
    //Reference to GT command
(_GT)
@R15
M=D

A=D
D=M
D=D-M
@_GT_TRUE
D;JGT
    //Is not less than, push false
@0
D=A
@SP
AM=M+1
A=A-1
M=D
@_GT_END
0;JMP
(_GT_TRUE)
    //Is less than, push true
@-1
D=A
@SP
AM=M+1
A=A-1
M=D
(_GT_END)
@R15
0;JMP
    //End GT
"""

eqInstance = \
"""@_EQ_%s
D=A
@_EQ
0;JMP
(_EQ_%s)"""

ltInstance = \
"""@_LT_%s
D=A
@_LT
0;JMP
(_LT_%s)"""

gtInstance = \
"""_GT_%s
D=A
@_GT
0;JMP
(_GT_%s)"""

addInstance = \
"""@SP
AM=M-1
D=M
A=A-1
M=D+M"""

negInstance = \
"""@SP
A=M-1
D=M
@0
D=A-D
@SP
A=M-1
M=D"""

subInstance = \
"""@SP
AM=M-1
D=M
A=A-1
M=D-M"""

andInstance = \
"""@SP
AM=M-1
D=M
A=A-1
M=D&M"""

orInstance = \
"""@SP
AM=M-1
D=M
A=A-1
M=D|M"""

notInstance = \
"""@SP
A=M-A
M=!M"""

haltInstance = \
"""(HALT)
@HALT
0;JMP"""

pushConstant = \
"""@%s
D=A
@SP
AM=M+1
A=A-1
M=D"""

pushTemp = \
"""@%s
D=A
@SP
AM=M+1
A=A-1
M=D"""

pushLocal = \
"""@%s
D=A
@%s
A=D+M
D=M
@SP
AM=M+1
A=A-1
M=D"""

popAtAddress = \
"""@SP
AM=M-1
D=M
@%s
M=D"""

popTemp = \
"""@SP
AM=M-1
D=M
@%s
M=D"""

popLocal = \
"""@%s
D=A
@%s
D=D+M
@R15
M=D
@SP
AM=M-1
D=M
@R15
A=M
M=D"""
