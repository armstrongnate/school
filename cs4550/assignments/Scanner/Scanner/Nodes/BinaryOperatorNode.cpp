//
//  BinaryOperatorNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode *r, ExpressionNode *l)
  : mRight(l), mLeft(l) {
    MSG("BinaryOperatorNode initializer");
}

BinaryOperatorNode::~BinaryOperatorNode() {
  MSG("BinaryOperatorNode deconstructor");
  delete mRight;
  delete mLeft;
}

int BinaryOperatorNode::Evaluate() {
  return 0;
}
