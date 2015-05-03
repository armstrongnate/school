//
//  IfStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 4/7/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

IfStatementNode::IfStatementNode(ExpressionNode *en, StatementNode *sn, StatementNode *elseStatementNode)
  : mExpressionNode(en), mStatementNode(sn), mElseStatementNode(elseStatementNode) {
    MSG("IfStatementNode initializer");
}

IfStatementNode::~IfStatementNode() {
  delete mExpressionNode;
  delete mStatementNode;
  delete mElseStatementNode;
}

void IfStatementNode::Interpret() {
  if (mExpressionNode->Evaluate()) {
    mStatementNode->Interpret();
  }
  else {
    if (mElseStatementNode) {
      mElseStatementNode->Interpret();
    }
  }
}

void IfStatementNode::Code(InstructionsClass &machineCode) {
  mExpressionNode->CodeEvaluate(machineCode);
  unsigned char *InsertAddress = machineCode.SkipIfZeroStack();
  unsigned char *address1 = machineCode.GetAddress();
  mStatementNode->Code(machineCode);
  unsigned char *address2 = machineCode.GetAddress();
  machineCode.SetOffset(InsertAddress, (int)(address2-address1));
}
