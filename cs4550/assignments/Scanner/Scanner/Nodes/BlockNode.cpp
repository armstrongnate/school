//
//  BlockNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

BlockNode::BlockNode(StatementGroupNode *sgn)
  : mStatementGroupNode(sgn) {
    MSG("BlockNode initializer");
}

BlockNode::~BlockNode() {
  MSG("BlockNode deconstructor");
  delete mStatementGroupNode;
}

void BlockNode::Interpret() {
  mStatementGroupNode->Interpret();
}
