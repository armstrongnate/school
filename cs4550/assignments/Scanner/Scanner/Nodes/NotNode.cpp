//
//  NotNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 4/7/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

NotNode::NotNode(ExpressionNode *e)
  : mExpressionNode(e) {
    MSG("NotNode initializer");
}

NotNode::~NotNode() {
  MSG("NotNode deconstructor");
}

int NotNode::Evaluate() {
  return !mExpressionNode->Evaluate();
}
