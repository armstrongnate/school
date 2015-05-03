//
//  MinusNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/24/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

MinusNode::MinusNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("MinusNode initializer");
}

int MinusNode::Evaluate() {
  return mLeft->Evaluate() - mRight->Evaluate();
}

void MinusNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopSubPush();
}
