symbolList = ['{','}','(',')','[',']','.',',',';','+','-','*','/','&','|','<','>','=','~']
keywordList = ['class','constructor','function','method','field','static',
'var','int','char','boolean','void','true','false','null','this',
'let','do','if','else','while','return']

class JackTokenizer:
  def __init__(self, fp):
    self.f = fp.read().replace('\r\n', '\n').replace('\r', '\n')
    self.tokens = []

    # end the string with a line break if it doesn't already
    self.f += '\n' if self.f[-1:] != '\n' else None
  def printString(self):
    print self.f
  def getTokens(self):
    tokenlist = []
    end = False
    f = self.f
    i = 0
    linecount = 0
    while end == False:
      i = 0
      if len(f) <= 0:
        break
      spacecount = 0
      #check for white space
      if f[i].isspace():
        if f[i] == '\n':
          linecount += 1
        f = f[i+1:]
        i = 0
        continue
      #check for // comments
      if f[:2] == '//':
        f = f[f.find('\n')+1:]
        continue

      #check for /* comments
      if f[:2] == '/*':
        f = f[2:]
        ec = f.find('*/')
        for j in range(ec+2):
          if f[j] == '\n':
            linecount+=1
        f = f[ec+2:]
        continue

      #find symbols
      if f[i] in symbolList:
        symbol = f[i]
        f = f[i+1:]
        tokenlist.append(('Symbol', symbol, linecount+1))
        continue

      #find digits
      if f[i].isdigit():
        num = ''
        while f[i].isdigit():
          num+=(f[i])
          i+=1
        f = f[i:]
        if int(num) <= 32767:
          tokenlist.append(('int', num, linecount+1))
        else:
          print "That number on line", linecount+1, "is too large."
        i = 0
        continue

      #find string constants
      if f[i] == '"':
        f = f[i+1:]
        eq = f.find('"')
        for j in range(i,eq):
          if f[j] == '\n':
            return "ERROR: You must close the quotes on line",linecount+1,"."
        stringconst = f[i:eq]
        f = f[eq+1:]
        tokenlist.append(('String Constant', stringconst, linecount+1))
        continue

      #find keywords and identifiers
      string = ''
      if f[i].isalnum() or f[i] == '_':
        while f[i].isalnum() or f[i] == '_':
          string+=(f[i])
          i+=1
        f = f[i:]
        if string in keywordList:
          tokenlist.append(('Keyword', string, linecount+1))
        else:
          tokenlist.append(('Identifier', string, linecount+1))
        i = 0
        continue

      else:
        print "syntax error on line", linecount+1,"."

    print 'linecount is ',linecount
    return tokenlist

def print_xml_test(tokens, xout):
  print >>xout, '<tokens>'
  for token in tokens:
    if token[0] == 'Symbol':
      symbol = token[1]
      if symbol == '<':
        symbol = '&lt;'
      elif symbol == '>':
        symbol = '&gt;'
      print >>xout, '<symbol> %s </symbol>' % symbol
    elif token[0] == 'Keyword':
      print >>xout, '<keyword> %s </keyword>' % token[1]
    elif token[0] == 'Identifier':
      print >>xout, '<identifier> %s </identifier>' % token[1]
    elif token[0] == 'int':
      print >>xout, '<integerConstant> %s </integerConstant>' % token[1]
    else:
      print >>xout, '<stringConstant> %s </stringConstant>' % token[1]
  print >>xout, '</tokens>'

  xout.close()

def main():
  fin = open('test.jack', 'r')
  xout = open('test_out.xml', 'w')
  tokens_out = open('tokens_list.txt', 'w')

  j = JackTokenizer(fin)
  tokens = j.getTokens()

  for token in tokens:
    print >>tokens_out, token

  print_xml_test(tokens, xout)

  fin.close()

if __name__ == '__main__':
  main()
