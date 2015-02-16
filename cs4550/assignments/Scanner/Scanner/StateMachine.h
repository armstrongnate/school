//
//  StateMachine.h
//  Scanner
//
//  Created by Nate Armstrong on 2/3/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef __Scanner__StateMachine__
#define __Scanner__StateMachine__

#include <stdio.h>
#include "Token.h"

enum MachineState {
  START_STATE, IDENTIFIER_STATE, INTEGER_STATE, CANTMOVE_STATE,
  LPAREN_STATE, RPAREN_STATE, LCURLY_STATE, RCURLY_STATE, SEMICOLON_STATE,
  LESS_STATE, GREATER_STATE, LESS_EQUAL_STATE, GREATER_EQUAL_STATE,
  PLUS_STATE, MINUS_STATE, EQUAL_STATE, INSERTION_STATE, EOF_STATE, LAST_STATE
};

enum CharacterType {
  LETTER_CHAR, WHITESPACE_CHAR, DIGIT_CHAR,
  LPAREN_CHAR, RPAREN_CHAR, LCURLY_CHAR, RCURLY_CHAR, SEMICOLON_CHAR,
  LESS_CHAR, GREATER_CHAR, EQUAL_CHAR, PLUS_CHAR, MINUS_CHAR, BAD_CHAR,
  LAST_CHAR
};

class StateMachine {
public:
  StateMachine();
  MachineState UpdateState(char currentCharacter, TokenType & correspondingTokenType);
private:
  MachineState mCurrentState;
  MachineState mLegalMoves[LAST_STATE][LAST_CHAR];
  TokenType mCorrespondingTokenTypes[LAST_STATE];
};

#endif /* defined(__Scanner__StateMachine__) */
