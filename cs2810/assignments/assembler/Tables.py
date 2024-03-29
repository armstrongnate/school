computationTable = {
    '0'   : '1101010',
    '1'   : '1111111',
    '-1'  : '1111010',
    'D'   : '1001100',
    'A'   : '1110000',
    '!D'  : '1001101',
    '!A'  : '1110001',
    '-D'  : '1001111',
    '-A'  : '1110011',
    'D+1' : '1011111',
    'A+1' : '1110111',
    'D-1' : '1001110',
    'A-1' : '1110010',
    'D+A' : '1000010',
    'D-A' : '1010011',
    'A-D' : '1000111',
    'D&A' : '1000000',
    'D|A' : '1010101',

    'M'   : '0110000',
    '!M'  : '0110001',
    '-M'  : '0110011',
    'M+1' : '0101010',
    'M-1' : '0110010',
    'D+M' : '0000010',
    'D-M' : '0010011',
    'M-D' : '0000111',
    'D&M' : '0000000',
    'D|M' : '0010101' }

destinationTable = {
    'null'  : '000',
    'M'     : '001',
    'D'     : '010',
    'MD'    : '011',
    'A'     : '100',
    'AM'    : '101',
    'AD'    : '110',
    'AMD'   : '111' }

jumpTable = {
    'null'  : '000',
    'JGT'   : '001',
    'JEQ'   : '010',
    'JGE'   : '011',
    'JLT'   : '100',
    'JNE'   : '101',
    'JLE'   : '110',
    'JMP'   : '111'
}