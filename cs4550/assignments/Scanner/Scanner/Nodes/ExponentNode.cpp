//
//  ExponentNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 5/4/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include <complex>

#include "Node.h"

ExponentNode::ExponentNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("ExponentNode initializer");
}

int ExponentNode::Evaluate() {
  return pow(mLeft->Evaluate(), mRight->Evaluate());
}

void ExponentNode::CodeEvaluate(InstructionsClass &machineCode) {
  MSG("ExponentNode CodeEvaluate");
}
