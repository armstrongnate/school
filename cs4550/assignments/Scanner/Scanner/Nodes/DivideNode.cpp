//
//  DivideNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/24/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

DivideNode::DivideNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("DivideNode initializer");
}

int DivideNode::Evaluate() {
  return mLeft->Evaluate() / mRight->Evaluate();
}
