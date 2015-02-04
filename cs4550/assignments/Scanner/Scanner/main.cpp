//
//  main.cpp
//  Scanner
//
//  Created by Nate Armstrong on 2/3/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include <iostream>
#include "Token.h"

int main(int argc, const char * argv[]) {
  // insert code here...
  Token t(IDENTIFIER_TOKEN, "void");
  t.CheckReserved();
  std::cout << "TOKEN: " << t << std::endl;
  std::cout << "Hello, World!\n";
  return 0;
}
