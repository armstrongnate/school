//
//  PlusEqualNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 5/2/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include <stdio.h>
#include "Node.h"

PlusEqualNode::PlusEqualNode(IdentifierNode *in, ExpressionNode *en)
: AssignmentStatementNode(in, en) {
  MSG("PlusEqualNode init");
}

PlusEqualNode::~PlusEqualNode() {
  MSG("PlusEqualNode deconstructor");
}

void PlusEqualNode::Interpret() {
  int exp_value = mExpressionNode->Evaluate();
  exp_value += mIdentifierNode->Evaluate();
  mIdentifierNode->SetValue(exp_value);
}

void PlusEqualNode::Code(InstructionsClass &machineCode) {
  machineCode.PushVariable(mIdentifierNode->GetIndex());
  mExpressionNode->CodeEvaluate(machineCode);
  machineCode.PopPopAddPush();
  machineCode.PopAndStore(mIdentifierNode->GetIndex());
}
