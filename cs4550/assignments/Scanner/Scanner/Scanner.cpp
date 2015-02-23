//
//  Scanner.cpp
//  Scanner
//
//  Created by Nate Armstrong on 2/9/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include "Scanner.h"
#include "StateMachine.h"

using namespace std;

Scanner::Scanner(const char *filename) {
  mFin.open(filename);
  mLineNumber = 1;
}

bool isBlockComment(string s) {
  return s.size() >= 2 && s.substr(0, 2) == "/*";
}

Token Scanner::GetNextToken() {
  StateMachine stateMachine;
  TokenType correspondingTokenType;
  MachineState currentState = stateMachine.GetCurrentState();
  string lexeme;
  bool comment = false;

  do {
    if (mFin.peek() == EOF) { exit(1); }
    char c = mFin.get();
    lexeme += c;
    if (c == '\n') {
      mLineNumber++;
    }
    if (lexeme == "/" && (mFin.peek() == '*' || mFin.peek() == '/')) {
      comment = true;
    }
    if (!comment) {
      currentState = stateMachine.UpdateState(c, correspondingTokenType);
    }
    if (!comment && (currentState == START_STATE || currentState == EOF_STATE)) {
      lexeme = "";
    }
    if (comment) {
      bool blockComment = isBlockComment(lexeme);
      if ((blockComment && lexeme.substr(lexeme.size() - 2, 2) == "*/") || (!blockComment && lexeme.back() == '\n')) {
        comment = false;
        lexeme = "";
        currentState = START_STATE;
      }
    }
  } while (currentState != CANTMOVE_STATE);

  if (!comment && correspondingTokenType == BAD_TOKEN) {
    cerr << "Could not build token from lexeme: " << lexeme;
    exit(1);
  }

  if (lexeme.back() == '\n') {
    mLineNumber--;
  }

  mFin.unget();
  lexeme.pop_back();
  Token token(correspondingTokenType, lexeme);

  return token;
}

int Scanner::GetLineNumber() {
  return mLineNumber;
}
