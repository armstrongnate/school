# This program allows the user to see different math formulas plotted graphically
# By the CS 2420 class
# Feb 2013

from graphics import *

def InfixToPostfix(infix):
    postfix = ""
    
    # Your algorithm here!
    
    return postfix

def EvaluatePostfix(x, postfix):
    y = x*x
    
    # Your algorithm here!
    
    return y

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

    