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
}

Token Scanner::GetNextToken() {
  StateMachine stateMachine;
  TokenType correspondingTokenType;
  MachineState currentState;
  string lexeme;

  do {
    if (mFin.peek() == EOF) { exit(1); }
    char c = mFin.get();
    lexeme += c;
    currentState = stateMachine.UpdateState(c, correspondingTokenType);
    if (currentState == START_STATE || currentState == EOF_STATE) lexeme = "";
  } while (currentState != CANTMOVE_STATE);

  if (correspondingTokenType == BAD_TOKEN) {
    cerr << "Could not build token from lexeme: " << lexeme;
    exit(1);
  }

  mFin.unget();
  lexeme.pop_back();
  Token token(correspondingTokenType, lexeme);

  return token;
}
