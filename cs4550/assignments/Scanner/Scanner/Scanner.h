//
//  Scanner.h
//  Scanner
//
//  Created by Nate Armstrong on 2/9/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef __Scanner__Scanner__
#define __Scanner__Scanner__

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Token.h"

class Scanner {
public:
  Scanner(const char *filename);
  Token GetNextToken();
  int GetLineNumber();
private:
  ifstream mFin;
  int mLineNumber;
};

#endif /* defined(__Scanner__Scanner__) */
