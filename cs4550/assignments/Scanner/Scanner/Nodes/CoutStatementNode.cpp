//
//  CoutStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

CoutStatementNode::CoutStatementNode() {
  MSG("CoutStatementNode initializer");
  mEndlNode = new EndlNode();
}

CoutStatementNode::~CoutStatementNode() {
  MSG("CoutStatementNode deconstructor");
  for (int i=0; i<mExpressionNodes.size(); i++) {
    delete mExpressionNodes.back();
    mExpressionNodes.pop_back();
  }
  delete mEndlNode;
}

void CoutStatementNode::Interpret() {
  for (int i=0; i<mExpressionNodes.size(); i++) {
    if (mExpressionNodes.at(i) == NULL) {
      mEndlNode->Evaluate();
    }
    else {
      cout << mExpressionNodes.at(i)->Evaluate();
    }
  }
}

void CoutStatementNode::Code(InstructionsClass &machineCode) {
  for (int i=0; i<mExpressionNodes.size(); i++) {
    if (mExpressionNodes.at(i) == NULL) {
      mEndlNode->CodeEvaluate(machineCode);
    }
    else {
      mExpressionNodes.at(i)->CodeEvaluate(machineCode);
      machineCode.PopAndWrite();
    }
  }
}

void CoutStatementNode::AddExpressionNode(ExpressionNode *en) {
  mExpressionNodes.push_back(en);
}

// MARK: - EndlNode

EndlNode::EndlNode() {}

EndlNode::~EndlNode() {}

int EndlNode::Evaluate(){
  cout << endl;
  return 0;
}

void EndlNode::CodeEvaluate(InstructionsClass &machineCode) {
  machineCode.WriteEndl();
}