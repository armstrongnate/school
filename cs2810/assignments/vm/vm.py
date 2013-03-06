SYMBOLS = ['_', '.', '$', ':']

COMMANDS = {
  'add':  0,
  'sub':  0,
  'neg':  0,
  'eg':   0,
  'gt':   0,
  'lt':   0,
  'and':  0,
  'or':   0,
  'not':  0
}

SEGMENTS = {
  'argument': True,
  'local':    True,
  'constant': True,
  'this':     True,
  'that':     True,
  'pointer':  True,
  'static':   True,
  'temp':     True
}

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

def parseLine(s, line_num):
  line = s
  if s.find("//") >= 0:
    s = s[:s.find('//')]
  s = s.strip()
  if len(s) < 1:
    return None
  s = s.split()

  # check: first word is a valid command
  if s[0] not in COMMANDS.keys():
    fail("Invalid command: " + s[0], line_num, line)
  elif s < 2: # return valid commands that don't take any arguments
    return (s[0])
  else: # check: right number of arguments
    if COMMANDS[s[0]] != len(s-1):
      fail("Wrong number of arguments.", line_num, line)
    else: # check: arguments are valid 
      if not isSymbol(s[1]):
        fail("Invalid symbol.", line_num, line)
      if len(s) > 2 and not isConstant(s[2]):
        fail("Invalid constant.", line_num, line)
        