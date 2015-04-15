//
//  main.cpp
//  Scanner
//
//  Created by Nate Armstrong on 2/3/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#include <iostream>
#include <assert.h>

#include "Token.h"
#include "Scanner.h"
#include "SymbolTable.h"
#include "Parser.h"
#include "Node.h"

void scan() {
  Scanner scanner("/Users/nate/school/cs4550/assignments/Scanner/Scanner/main.txt");
  Token token;
  do {
    token = scanner.GetNextToken();
    cout << token << " " << scanner.GetLineNumber() << endl;
  } while (token.GetTokenType() != EOF_TOKEN);
}

void testParser() {
  SymbolTable symbolTable;
  Scanner scanner("/Users/nate/school/cs4550/assignments/Scanner/Scanner/main.txt");
  Parser parser(&scanner, &symbolTable);
  StartNode *root = parser.Start();
  root->Interpret();
}

void testSymbolTable() {
  SymbolTable table;

  // Exists, AddEntry, GetCount
  assert(table.GetCount() == 0);
  assert(!table.Exists("foo"));
  table.AddEntry("foo");
  assert(table.Exists("foo"));
  assert(table.GetCount() == 1);

  // GetIndex of 'foo' should be 0
  assert(table.GetIndex("foo") == 0);

  // GetValue for 'foo' should be the default, 0
  assert(table.GetValue("foo") == 0);

  // SetValue
  table.SetValue("foo", 1);
  assert(table.GetValue("foo") == 1);

  // Failures
//  table.AddEntry("foo"); // variable already exists
//  table.SetValue("bar", 3); // variable does not exist
  table.GetValue("baz"); // variable does not exist
}

int main(int argc, const char * argv[]) {
  // mCode will be an array of bytes representint source code that we are compiling
  // it should start with these first 3 bytes and
  // end with the last 2 bytes
  // eg: {0x55, 0x8B, 0xEC, <MY STUFF WILL BE HERE>, 0X5d, 0XC3};
  unsigned char mCode[] = {0x55, 0x8B, 0xEC, 0X5d, 0XC3};
  cout << "About to Execute the machine code...\n";
  void * ptr = mCode;
  void (*f)(void);
  f = (void (*)(void)) ptr;
  f(); // call the array as if it were a function
  cout << "There and back again!\n\n";
  return 0;
}
