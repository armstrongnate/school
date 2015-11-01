//
//  AssignmentStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode *in,
                                                 ExpressionNode *en)
: mIdentifierNode(in), mExpressionNode(en) {
  MSG("AssignmentStatementNode initializer");
}

AssignmentStatementNode::~AssignmentStatementNode() {
  MSG("AssignmentStatementNode deconstructor");
  delete mIdentifierNode;
  delete mExpressionNode;
}

void AssignmentStatementNode::Interpret() {
  mIdentifierNode->SetValue(mExpressionNode->Evaluate());
}

void AssignmentStatementNode::Code(InstructionsClass &machineCode) {
  mExpressionNode->CodeEvaluate(machineCode);
  machineCode.PopAndStore(mIdentifierNode->GetIndex());
}
