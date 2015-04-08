//
//  DeclarationStatementNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

DeclarationStatementNode::DeclarationStatementNode(IdentifierNode *in)
  : mIdentifierNode(in) {
    MSG("DeclarationStatementNode initializer");
}

DeclarationStatementNode::~DeclarationStatementNode() {
  MSG("DeclarationStatementNode deconstructor");
  delete mIdentifierNode;
}

void DeclarationStatementNode::Interpret() {
  mIdentifierNode->DeclareVariable();
}
