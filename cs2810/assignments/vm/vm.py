import sys
import os

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
  'not':  0,
  'pop':  3,
  'push': 3,
  'local': 1,
  'goto': 1,
  'if-goto': 1,
  'function': 2,
  'call': 2,
  'return': 0
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

  # handling pop and push
  if s[0] == 'pop' or s[0] == 'push':
    if s[1] not in SEGMENTS:
      fail("Argument of pop/push not valid.", line_num, line)

    if s[0] == 'pop':
      if s[1] == 'constant':
        fail("Invalid command 'constant' with pop.", line_num, line)
      return ('pop', s[1], s[2])
    else:
      return ('push', s[1], s[2])

  # check: first word is a valid command
  if s[0] not in COMMANDS.keys():
    fail("Invalid command: " + s[0], line_num, line)
  elif s < 2: # return valid commands that don't take any arguments
    return (s[0])
  else: # check: right number of arguments
    if COMMANDS[s[0]] != len(s)-1:
      fail("Wrong number of arguments.", line_num, line)
    else: # check: arguments are valid 
      if len(s) > 1 and not isSymbol(s[1]):
        fail("Invalid symbol.", line_num, line)
      if len(s) > 2 and not isConstant(s[2]):
        fail("Invalid constant.", line_num, line)
      t = ()
      for v in s:
        t = t+(v,)
  return t

def parseFile(fin, instructions):
  fin = open(fin, 'r')
  fin = fin.readlines()
  for i in range(len(fin)):
    if parseLine(str(fin[i]), i):
      instructions.append(parseLine(fin[i], i))

def is_valid_vm_file(fin):
  return fin[-3:] == '.vm' and os.path.isfile(fin)

def main(*argv):
  vm_files = []
  instructions = []
  if len(sys.argv) < 2:
    print "No vm file specified."
    sys.exit()
  fin = os.path.abspath(sys.argv[1])
  if fin[-3:] == '.vm':
    if is_valid_vm_file(fin):
      vm_files.append(fin)
      fout = fin[:-3] + '.asm'
    else:
      print "File not found: %s" % fin
  else:    
    if os.path.isdir(fin):
      fout = os.path.join(fin, os.path.basename(fin) + '.asm')
      for f in os.listdir(fin):
        f = os.path.join(fin, f)
        if is_valid_vm_file(f):
          vm_files.append(f)
    else:
      print "No such file or directory found: %s" % fin

  for vm_file in vm_files:
    print "Processing " + os.path.basename(vm_file) + "..."
    parseFile(vm_file, instructions)
  print instructions
main()
