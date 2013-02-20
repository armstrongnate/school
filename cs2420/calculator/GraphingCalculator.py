# This program allows the user to see different math formulas plotted graphically
# By the CS 2420 class
# Feb 2013
import _tkinter
from graphics import *
from Stack import *

MATH_OPERATORS = {
  '+': 0,
  '-': 0, 
  '*': 1,
  '/': 1,
}

def InfixToPostfix(infix):
    postfix = ""
    stack = Stack()
    for c in infix:
        if c.isdigit() or c.isalpha():
          postfix += c
        elif c == ')':
          while stack.top() != '(':
            postfix += stack.pop()
          stack.pop()
        elif stack.isEmpty() or c == '(' or stack.top() == '(':
            stack.push(c)
        elif c in MATH_OPERATORS:
          if MATH_OPERATORS[c] <= MATH_OPERATORS[stack.top()]:
            postfix += stack.pop()
            stack.push(c)
          else:
            stack.push(c)
    while not stack.isEmpty():
      postfix += stack.pop()
    
    return postfix

def EvaluatePostfix(x, postfix):
    stack = Stack()
    for c in postfix:
      if c.isdigit():
        stack.push(c)
      elif c.isalpha():
        stack.push(x)
      elif c in MATH_OPERATORS:
        right = str(stack.pop())
        left = str(stack.pop())
        stack.push(str(eval(left+c+right)))
    return float(stack.top())

def PrintInstructions():
    print "This program ..."
    
def main():
    PrintInstructions()
    userInput = raw_input("Enter your expression. Example: '3*x*x+2*x-7' ")
    postFix = InfixToPostfix(userInput)
    win = GraphWin("Graphing Calculator", 600, 600)

    left = -5
    right = 5
    bottom = -5
    top = 5
    win.setCoords(left,bottom, right, top)

    x = left
    xInc = .1
    while x<right:
        y = EvaluatePostfix(x, postFix)
        x2 = x+xInc
        y2 = EvaluatePostfix(x2, postFix)
        line = Line(Point(x,y), Point(x2,y2))
        line.draw(win)
        x += xInc
        
    p = win.getMouse()
    win.close()

main()