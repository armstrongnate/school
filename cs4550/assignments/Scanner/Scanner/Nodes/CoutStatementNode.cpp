//
//  CoutStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

CoutStatementNode::CoutStatementNode(ExpressionNode *en)
  : mExpressionNode(en) {
    MSG("CoutStatementNode initializer");
}

CoutStatementNode::~CoutStatementNode() {
  MSG("CoutStatementNode deconstructor");
  delete mExpressionNode;
}

void CoutStatementNode::Interpret() {
  cout << mExpressionNode->Evaluate() << endl;
}

void CoutStatementNode::Code(InstructionsClass &machineCode) {
  mExpressionNode->CodeEvaluate(machineCode);
  machineCode.PopAndWrite();
}
