//
//  StartNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

StartNode::StartNode(ProgramNode *pn)
  : mProgramNode(pn) {
    MSG("StartNode initializer");
}

StartNode::~StartNode() {
  MSG("StartNode deconstructor");
  delete mProgramNode;
}

void StartNode::Interpret() {
  mProgramNode->Interpret();
}

void StartNode::Code(InstructionsClass &machineCode) {
  mProgramNode->Code(machineCode);
}
