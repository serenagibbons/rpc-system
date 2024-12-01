// --------------------------------------------------------------
// File: arithmetic.stub.cpp
// Author: Serena GIbbons
// --------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "arithmetic.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

#define SIZE 4

using namespace std;
using namespace C150NETWORK;

// Arithmetic Function Handlers
void __subtract(int x, int y) {
  int result = subtract(x, y);
  Buffer b;
  serializeInt(&b, result);
  RPCSTUBSOCKET->write(b.buf, b.length);
  b.reset();
}

void __divide(int x, int y) {
  int result = divide(x, y);
  Buffer b;
  serializeInt(&b, result);
  RPCSTUBSOCKET->write(b.buf, b.length);
  b.reset();
}

void __add(int x, int y) {
  int result = add(x, y);
  Buffer b;
  serializeInt(&b, result);
  RPCSTUBSOCKET->write(b.buf, b.length);
  b.reset();
}

void __multiply(int x, int y) {
  int result = multiply(x, y);
  Buffer b;
  serializeInt(&b, result);
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

  if (func_name == "subtract") {
    int x = deserializeInt(RPCSTUBSOCKET);
    int y = deserializeInt(RPCSTUBSOCKET);
    __subtract(x, y);
  } 
  else if (func_name == "divide") {
    int x = deserializeInt(RPCSTUBSOCKET);
    int y = deserializeInt(RPCSTUBSOCKET);
    __divide(x, y);
  } 
  else if (func_name == "add") {
    int x = deserializeInt(RPCSTUBSOCKET);
    int y = deserializeInt(RPCSTUBSOCKET);
    __add(x, y);
  } 
  else if (func_name == "multiply") {
    int x = deserializeInt(RPCSTUBSOCKET);
    int y = deserializeInt(RPCSTUBSOCKET);
    __multiply(x, y);
  } 
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}
