//
//  PlusNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

PlusNode::PlusNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("PlusNode initializer");
}

int PlusNode::Evaluate() {
  return mLeft->Evaluate() + mRight->Evaluate();
}

void PlusNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopAddPush();
}
