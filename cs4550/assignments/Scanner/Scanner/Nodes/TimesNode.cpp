//
//  TimesNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/24/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

TimesNode::TimesNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("TimesNode initializer");
}

int TimesNode::Evaluate() {
  return mLeft->Evaluate() * mRight->Evaluate();
}

void TimesNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopMulPush();
}
