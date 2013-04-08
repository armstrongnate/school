class CompilationEngine:
  def __init__(tokens_list, out_file):
    self.tokens_list = tokens_list
    self.out_file = out_file
    self.current_index = 0
    self.indent = 0
    self.line_num = 0

  def nextToken():

    self.line_num = self.tokens_list[self.current_index+1][2]
    return self.tokens_list[self.current_index+1]

  def peek():
    return self.tokens_list[self.current_index+1]