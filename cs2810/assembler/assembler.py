# helper functions
SYMBOLS = ['_', '.', '$', ':']

def isSymbol(s):
  if len(s) < 1:
    return False
  if s[0].isdigit():
    return False
  for c in s:
    if c not in SYMBOLS:
      if not c.alnum():
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
  result_list = []
  line = s
  if s.find("//") >= 0:
    s = s[:s.find('//')]
  s = s.strip()
  if len(s) < 1:
    return None

  # check if address instruction
  if s[0] == '@':
    s = [1:].strip()
    if isSymbol(s) or isConstant(s):
      result_list.append(('A_INSTRUCTION', s, line, line_num))

  # check if symbol 
  if s[0] == '(' and s[-1] == ')':
    s = [1:-1]
    if isSymbol(s):
      result_list.append(('L_INSTRUCTION', s, line, line_num))

  # handle equals sign
  if '=' in s:
    destination = s[s:s.find('=')]
    if destination not in DESTINATIONS:
      fail("Invalid Destination", line_num, s)
  else:
    destination = ''

  # check if jump
  if ';' in s:
    jump = s[s.find(';')+1:]
    if jump not in JUMPS:
      fail("Invalid Jump", line_num, s)
  else:
    jump = ''