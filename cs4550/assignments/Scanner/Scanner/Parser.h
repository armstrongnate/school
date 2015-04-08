//
//  Parser.h
//  Scanner
//
//  Created by Nate Armstrong on 3/24/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef __Scanner__Parser__
#define __Scanner__Parser__

#include <stdio.h>

#include "Token.h"

class Scanner;
class SymbolTable;
class StartNode;
class ProgramNode;
class Token;
class StatementGroupNode;
class StatementNode;
class DeclarationStatementNode;
class AssignmentStatementNode;
class CoutStatementNode;
class IfStatementNode;
class WhileStatementNode;
class IdentifierNode;
class ExpressionNode;
class BlockNode;
class NotNode;
class IntegerNode;

class Parser {
public:
  Parser(Scanner *scanner, SymbolTable *st);
  StartNode * Start();
private:
  Scanner * mScanner;
  SymbolTable * mSymbolTable;
  ProgramNode * Program();
  Token Match(TokenType expectedType);
  BlockNode * Block();
  StatementGroupNode * StatementGroup();
  StatementNode * Statement();
  DeclarationStatementNode * DeclarationStatement();
  AssignmentStatementNode * AssignmentStatement();
  CoutStatementNode * CoutStatement();
  IfStatementNode * IfStatement();
  WhileStatementNode * WhileStatement();
  IdentifierNode * Identifier();
  ExpressionNode * Expression();
  ExpressionNode * Relational();
  ExpressionNode * Side();
  ExpressionNode * Term();
  ExpressionNode * Factor();
  ExpressionNode * Or();
  ExpressionNode * And();
  IntegerNode * Integer();
  NotNode * Not();
};

#endif /* defined(__Scanner__Parser__) */
