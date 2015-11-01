//
//  SymbolTable.h
//  Scanner
//
//  Created by Nate Armstrong on 2/23/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

#ifndef __Scanner__SymbolTable__
#define __Scanner__SymbolTable__

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class SymbolTable {

  struct Symbol {
    string mLabel;
    int mValue;
  };

public:
  SymbolTable();
  bool Exists(string s);
  void AddEntry(string s);
  int GetValue(string s);
  void SetValue(string s, int v);
  int GetIndex(string s);
  int GetCount();
private:
  vector<Symbol> mSymbols;
};

#endif /* defined(__Scanner__SymbolTable__) */
