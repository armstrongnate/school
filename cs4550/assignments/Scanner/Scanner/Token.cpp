//
//  Token.cpp
//  Scanner
//
//  Created by Nate Armstrong on 2/3/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Token.h"

Token::Token() {}

Token::Token(TokenType type, const string &lexeme) {
  mType = type;
  mLexeme = lexeme;
}

void Token::CheckReserved() {
  const char *lexeme = mLexeme.c_str();
  if (std::strcmp(lexeme, "void") == 0) {
    mType = VOID_TOKEN;
  }
  else if (std::strcmp(lexeme, "main")) {
    mType = MAIN_TOKEN;
  }
  else if (std::strcmp(lexeme, "int")) {
    mType = INT_TOKEN;
  }
  else if (std::strcmp(lexeme, "cout")) {
    mType = COUT_TOKEN;
  }
  else if (std::strcmp(lexeme, "for")) {
    mType = FOR_TOKEN;
  }
  else if (std::strcmp(lexeme, "if")) {
    mType = IF_TOKEN;
  }
  else if (std::strcmp(lexeme, "while")) {
    mType = WHILE_TOKEN;
  }
  else if (std::strcmp(lexeme, "do")) {
    mType = DO_TOKEN;
  }
}

ostream & operator<<(ostream &out, const Token &token) {
  cout << token.GetTokenTypeName() << " " << token.GetLexeme();
  return out;
}
