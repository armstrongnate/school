//
//  ProgramNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

ProgramNode::ProgramNode(BlockNode *bn)
  : mBlockNode(bn) {
    MSG("ProgramNode initializer");
}

ProgramNode::~ProgramNode() {
  MSG("ProgramNode deconstructor");
  delete mBlockNode;
}
