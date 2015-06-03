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
  if (mElseStatementNode) {
    mExpressionNode->CodeEvaluate(machineCode);
    unsigned char *offset1 = machineCode.SkipIfZeroStack();
    unsigned char *address1 = machineCode.GetAddress();
    mStatementNode->Code(machineCode);
    unsigned char *offset2 = machineCode.Jump();
    unsigned char *address2 = machineCode.GetAddress();
    mElseStatementNode->Code(machineCode);
    unsigned char *address3 = machineCode.GetAddress();
    machineCode.SetOffset(offset1, (int)(address2-address1));
    machineCode.SetOffset(offset2, (int)(address3-address2));

  } else {
    mExpressionNode->CodeEvaluate(machineCode);
    unsigned char *offset1 = machineCode.SkipIfZeroStack();
    unsigned char *address1 = machineCode.GetAddress();
    mStatementNode->Code(machineCode);
    unsigned char *address2 = machineCode.GetAddress();
    machineCode.SetOffset(offset1, (int)(address2-address1));
  }
}
