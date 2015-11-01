//
//  DoWhileStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 5/4/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

DoWhileStatementNode::DoWhileStatementNode(ExpressionNode *en, StatementNode *sn)
  : mExpressionNode(en), mStatementNode(sn) {
    MSG("DoWhileStatementNode initializer");
}

DoWhileStatementNode::~DoWhileStatementNode() {
  delete mExpressionNode;
  delete mStatementNode;
}

void DoWhileStatementNode::Interpret() {
  do
    mStatementNode->Interpret();
  while (mExpressionNode->Evaluate());
}

void DoWhileStatementNode::Code(InstructionsClass &machineCode) {
  unsigned char * addressEx = machineCode.GetAddress();
  mExpressionNode->CodeEvaluate(machineCode);
  unsigned char * addressValue = machineCode.SkipIfZeroStack();
  unsigned char * address1 = machineCode.GetAddress();
  mStatementNode->Code(machineCode);
  unsigned char * jmp = machineCode.Jump();
  unsigned char * address2 = machineCode.GetAddress();
  machineCode.SetOffset(addressValue, (int)(address2 - address1));
  machineCode.SetOffset(jmp, (int) (addressEx - address2));
}
