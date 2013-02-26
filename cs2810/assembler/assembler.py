# helper functions
from Tables import *
SYMBOLS = ['_', '.', '$', ':']

def isSymbol(s):
  if len(s) < 1:
    return False
  if s[0].isdigit():
    return False
  for c in s:
    if c not in SYMBOLS:
      if not c.isalnum():
        return False
  return True

def isConstant(s):
  if len(s) < 1 or len(s) > 5:
    return False
  if int(s) < 0 or int(s) > 32767:
    return False
  return True

def fail(message, source_line, source_input_line):
  raise Exception("Error: %s. Source Line: %s. Source Input Line: %s" %(message, source_line, source_input_line))

# parsing a line

def parseLine(s, line_num):
  destination = ''
  comp = ''
  jmp = ''
  result_list = []
  line = s
  if s.find("//") >= 0:
    s = s[:s.find('//')]
  s = s.strip()
  if len(s) < 1:
    return None
  # check if address instruction
  if s[0] == '@':
    s = s[1:].strip()
    if isSymbol(s) or isConstant(s):
      return str(('A_INSTRUCTION', s, line, line_num))

  # check if symbol 
  if s[0] == '(' and s[-1] == ')':
    s = s[1:-1]
    if isSymbol(s):
      return str(('L_INSTRUCTION', s, line, line_num))

  # handle equals sign aka destination
  if '=' in s:
    destination = s[:s.find('=')]
    comp = s[s.find('=')+1:]
    if destination not in destinationTable:
      fail("Invalid Destination", line_num, s)
  else:
    destination = ''
  # check if jump
  print s
  if ';' in s:
    comp = s[:s.find(';')]
    jmp = s[s.find(';')+1:]
    if jmp not in jumpTable:
      fail("Invalid Jump", line_num, line)
  elif ';' not in s:
    jmp = ''
  else:
    fail("Invalid Syntax", line_num, line)

  return str(("C_INSTRUCTION", destination, comp, jmp, line, line_num))

fn = open('../projects/06/rect/RectL.asm', 'r')

output = []
i = 0
for line in fn:
  s = parseLine(line, i)
  if s == None:
    continue
  output.append(parseLine(line, i)+"\n")
  i += 1

fn.close()

hack = open('output.hack', 'wr')
for line in output:
  hack.write(line)
hack.close()