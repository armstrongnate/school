//
//  BinaryOperatorNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode *r, ExpressionNode *l)
  : mRight(l), mLeft(l) {
    MSG("BinaryOperatorNode initializer");
}

BinaryOperatorNode::~BinaryOperatorNode() {
  MSG("BinaryOperatorNode deconstructor");
  delete mRight;
  delete mLeft;
}

// MARK: - LessNode

LessNode::LessNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("LessNode initializer");
}

int LessNode::Evaluate() {
  return mLeft < mRight;
}

// MARK: - LessEqualNode

LessEqualNode::LessEqualNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("LessEqualNode initializer");
}

int LessEqualNode::Evaluate() {
  return mLeft <= mRight;
}

// MARK: - GreaterNode

GreaterNode::GreaterNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("GreaterNode initializer");
}

int GreaterNode::Evaluate() {
  return mLeft > mRight;
}

// MARK: - GreaterEqualNode

GreaterEqualNode::GreaterEqualNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("GreaterEqualNode initializer");
}

int GreaterEqualNode::Evaluate() {
  return mLeft >= mRight;
}

// MARK: - EqualNode

EqualNode::EqualNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("EqualNode initializer");
}

int EqualNode::Evaluate() {
  return mLeft == mRight;
}

// MARK: - NotEqualNode

NotEqualNode::NotEqualNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("NotEqualNode initializer");
}

int NotEqualNode::Evaluate() {
  return mLeft != mRight;
}

// MARK: - OrNode

OrNode::OrNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("OrNode initializer");
}

int OrNode::Evaluate() {
  return mLeft || mRight;
}

// MARK: - AndNode

AndNode::AndNode(ExpressionNode *r, ExpressionNode *l)
  : BinaryOperatorNode(r, l) {
    MSG("AndNode initializer");
}

int AndNode::Evaluate() {
  return mLeft && mRight;
}
