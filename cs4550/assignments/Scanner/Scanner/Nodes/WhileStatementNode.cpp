//
//  WhileStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 4/7/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

WhileStatementNode::WhileStatementNode(ExpressionNode *en, StatementNode *sn)
  : mExpressionNode(en), mStatementNode(sn) {
    MSG("WhileStatementNode initializer");
}

WhileStatementNode::~WhileStatementNode() {
  delete mExpressionNode;
  delete mStatementNode;
}

void WhileStatementNode::Interpret() {
  while (mExpressionNode->Evaluate()) {
    mStatementNode->Interpret();
  }
}
