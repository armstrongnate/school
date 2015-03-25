//
//  Node.h
//  Scanner
//
//  Created by Nate Armstrong on 3/2/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef __Scanner__Node__
#define __Scanner__Node__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "SymbolTable.h"
#include "Debug.h"

using namespace std;

class Node;
class StartNode;
class ProgramNode;
class BlockNode;
class StatementGroupNode;
class StatementNode;
class DeclarationStatementNode;
class AssignmentStatementNode;
class CoutStatementNode;
class IdentifierNode;
class ExpressionNode;
class IntegerNode;
class BinaryOperatorNode;
class PlusNode;
class MinusNode;
class TimesNode;
class DivideNode;
class LessNode;
class LessEqualNode;
class GreaterNode;
class GreaterEqualNode;
class EqualNode;
class NodeEqualNode;

class Node {
public:
  virtual ~Node();
};

class StartNode: public Node {
public:
  StartNode(ProgramNode *programNode);
  ~StartNode();
private:
  ProgramNode *mProgramNode;
};

class ProgramNode: public Node {
public:
  ProgramNode(BlockNode *blockNode);
  ~ProgramNode();
private:
  BlockNode *mBlockNode;
};

class BlockNode: public Node {
public:
  BlockNode(StatementGroupNode *statementGroupNode);
  ~BlockNode();
private:
  StatementGroupNode *mStatementGroupNode;
};

class StatementGroupNode: public Node {
public:
  StatementGroupNode();
  ~StatementGroupNode();
  void AddStatement(StatementNode *statementNode);
private:
  vector<StatementNode*> mStatementNodes;
};

class StatementNode: public Node {
public:
  StatementNode();
  ~StatementNode();
private:
};

class DeclarationStatementNode: public StatementNode {
public:
  DeclarationStatementNode(IdentifierNode *identifierNode);
  ~DeclarationStatementNode();
private:
  IdentifierNode *mIdentifierNode;
};

class AssignmentStatementNode: public StatementNode {
public:
  AssignmentStatementNode(IdentifierNode *identifierNode, ExpressionNode *expressionNode);
  ~AssignmentStatementNode();
private:
  IdentifierNode *mIdentifierNode;
  ExpressionNode *mExpressionNode;
};

class CoutStatementNode: public StatementNode {
public:
  CoutStatementNode(ExpressionNode *expressionNode);
  ~CoutStatementNode();
private:
  ExpressionNode *mExpressionNode;
};

class ExpressionNode {
public:
  virtual ~ExpressionNode();
  virtual int Evaluate() = 0;
private:
};

class IntegerNode: public ExpressionNode {
public:
  IntegerNode(int value);
  int Evaluate();
private:
  int mValue;
};

class IdentifierNode: public ExpressionNode {
public:
  IdentifierNode(string label, SymbolTable *symbolTable);
  ~IdentifierNode();
  int Evaluate();
  void DeclareVariable();
  void SetValue(int value);
  int GetIndex();
private:
  string mLabel;
  SymbolTable *mSymbolTable;
};

class BinaryOperatorNode: public ExpressionNode {
public:
  BinaryOperatorNode(ExpressionNode *right, ExpressionNode *left);
  ~BinaryOperatorNode();
private:
protected:
  ExpressionNode *mRight;
  ExpressionNode *mLeft;
};

class PlusNode: public BinaryOperatorNode {
public:
  PlusNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class MinusNode: public BinaryOperatorNode {
public:
  MinusNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class TimesNode: public BinaryOperatorNode {
public:
  TimesNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class DivideNode: public BinaryOperatorNode {
public:
  DivideNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class LessNode: public BinaryOperatorNode {
public:
  LessNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class LessEqualNode: public BinaryOperatorNode {
public:
  LessEqualNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class GreaterNode: public BinaryOperatorNode {
public:
  GreaterNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class GreaterEqualNode: public BinaryOperatorNode {
public:
  GreaterEqualNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class EqualNode: public BinaryOperatorNode {
public:
  EqualNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

class NotEqualNode: public BinaryOperatorNode {
public:
  NotEqualNode(ExpressionNode *left, ExpressionNode *right);
  int Evaluate();
private:
};

#endif /* defined(__Scanner__Node__) */
