// --------------------------------------------------------------
// File: strings.stub.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "strings.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace C150NETWORK;

// Strings Function Handlers
void __concat(string s1, string s2) {
  string result = concat(s1, s2);
  Buffer b;
  serialize(&b, result);
  RPCSTUBSOCKET->write(b.buf, b.length);
  b.reset();
}

void __badFunction(const char *functionName) {
  const char *error = "BAD";
  RPCSTUBSOCKET->write(error, strlen(error) + 1);
}

// Dispatcher Function
void dispatchFunction() {
  if (RPCSTUBSOCKET->eof()) 
    return;

  string func_name = deserializeString(RPCSTUBSOCKET);
  if (func_name.empty()) 
    return;

  if (func_name == "concat") {
    string s1 = deserializeString(RPCSTUBSOCKET);
    string s2 = deserializeString(RPCSTUBSOCKET);
    __concat(s1, s2);
  } 
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}
