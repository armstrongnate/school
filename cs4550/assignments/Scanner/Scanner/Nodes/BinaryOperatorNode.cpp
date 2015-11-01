//
//  BinaryOperatorNode.cpp
//  Scanner
//
//  Created by Nate Armstrong on 3/16/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Node.h"

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode *l, ExpressionNode *r)
  : mLeft(l), mRight(r) {
    MSG("BinaryOperatorNode initializer");
}

BinaryOperatorNode::~BinaryOperatorNode() {
  MSG("BinaryOperatorNode deconstructor");
  delete mRight;
  delete mLeft;
}

// MARK: - LessNode

LessNode::LessNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("LessNode initializer");
}

int LessNode::Evaluate() {
  return mLeft->Evaluate() < mRight->Evaluate();
}

void LessNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopLessPush();
}

// MARK: - LessEqualNode

LessEqualNode::LessEqualNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("LessEqualNode initializer");
}

int LessEqualNode::Evaluate() {
  return mLeft->Evaluate() <= mRight->Evaluate();
}

void LessEqualNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopLessEqualPush();
}

// MARK: - GreaterNode

GreaterNode::GreaterNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("GreaterNode initializer");
}

int GreaterNode::Evaluate() {
  return mLeft->Evaluate() > mRight->Evaluate();
}

void GreaterNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopGreaterPush();
}

// MARK: - GreaterEqualNode

GreaterEqualNode::GreaterEqualNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("GreaterEqualNode initializer");
}

int GreaterEqualNode::Evaluate() {
  return mLeft->Evaluate() >= mRight->Evaluate();
}

void GreaterEqualNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopGreaterEqualPush();
}

// MARK: - EqualNode

EqualNode::EqualNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("EqualNode initializer");
}

int EqualNode::Evaluate() {
  return mLeft->Evaluate() == mRight->Evaluate();
}

void EqualNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopEqualPush();
}

// MARK: - NotEqualNode

NotEqualNode::NotEqualNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("NotEqualNode initializer");
}

int NotEqualNode::Evaluate() {
  return mLeft->Evaluate() != mRight->Evaluate();
}

void NotEqualNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopNotEqualPush();
}

// MARK: - OrNode

OrNode::OrNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("OrNode initializer");
}

int OrNode::Evaluate() {
  return mLeft->Evaluate() || mRight->Evaluate();
}

void OrNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopOrPush();
}

// MARK: - AndNode

AndNode::AndNode(ExpressionNode *l, ExpressionNode *r)
  : BinaryOperatorNode(l, r) {
    MSG("AndNode initializer");
}

int AndNode::Evaluate() {
  return mLeft->Evaluate() && mRight->Evaluate();
}

void AndNode::CodeEvaluate(InstructionsClass &machineCode) {
  mLeft->CodeEvaluate(machineCode);
  mRight->CodeEvaluate(machineCode);
  machineCode.PopPopAndPush();
}
