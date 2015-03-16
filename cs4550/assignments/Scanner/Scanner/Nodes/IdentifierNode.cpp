//
//  IdentifierNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

IdentifierNode::IdentifierNode(string l, SymbolTable *st)
  : mLabel(l), mSymbolTable(st) {
    MSG("IdentifierNode initializer");
}

IdentifierNode::~IdentifierNode() {
  MSG("IdentifierNode deconstructor");
}

int IdentifierNode::Evaluate() {
  return mSymbolTable->GetValue(mLabel);
}

void IdentifierNode::DeclareVariable() {
  mSymbolTable->AddEntry(mLabel);
}

void IdentifierNode::SetValue(int value) {
  mSymbolTable->SetValue(mLabel, value);
}

int IdentifierNode::GetIndex() {
  return mSymbolTable->GetIndex(mLabel);
}
