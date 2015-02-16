//
//  main.cpp
//  Scanner
//
//  Created by Nate Armstrong on 2/3/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include <iostream>
#include "Token.h"
#include "Scanner.h"

int main(int argc, const char * argv[]) {
  Scanner scanner("/Users/nate/school/cs4550/assignments/Scanner/Scanner/main.txt");
  Token token;
  do {
    token = scanner.GetNextToken();
    cout << token << endl;
  } while (token.GetTokenType() != EOF_TOKEN);

  return 0;
}
