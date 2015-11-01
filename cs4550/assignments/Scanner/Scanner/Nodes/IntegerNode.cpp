//
//  IntegerNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

IntegerNode::IntegerNode(int val)
  : mValue(val) {
    MSG("IntegerNode intializer");
}

int IntegerNode::Evaluate() {
  return mValue;
}

void IntegerNode::CodeEvaluate(InstructionsClass &machineCode) {
  machineCode.PushValue(this->mValue);
}
