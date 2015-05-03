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

void WhileStatementNode::Code(InstructionsClass &machineCode) {
  mExpressionNode->CodeEvaluate(machineCode);
  unsigned char *address0 = machineCode.GetAddress();
  unsigned char *offset1 = machineCode.SkipIfZeroStack();
  unsigned char *address1 = machineCode.GetAddress();
  mStatementNode->Code(machineCode);
  unsigned char *offset2 = machineCode.Jump();
  unsigned char *address2 = machineCode.GetAddress();
  machineCode.SetOffset(offset1, (int)(address2-address1));
  machineCode.SetOffset(offset2, (int)(address0-address2));
}
