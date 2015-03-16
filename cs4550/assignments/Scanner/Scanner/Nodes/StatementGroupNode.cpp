//
//  StatementGroupNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

StatementGroupNode::StatementGroupNode() {
  MSG("StatementGroupNode initializer");
}

StatementGroupNode::~StatementGroupNode() {
  MSG("StatementGroupNode deconstructor");
  for (int i=0; i<mStatementNodes.size(); i++) {
    delete mStatementNodes[i];
  }
}

void StatementGroupNode::AddStatement(StatementNode *statementNode) {
  mStatementNodes.push_back(statementNode);
}
