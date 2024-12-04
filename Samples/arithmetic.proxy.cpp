// --------------------------------------------------------------
// File: arithmetic.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "arithmetic.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
using namespace C150NETWORK;

// RPC Function Implementation
int remoteProcedureCall(const string &functionName, int x, int y) {
  Buffer b;
  serialize(&b, functionName);
  serialize(&b, x);
  serialize(&b, y);
  RPCPROXYSOCKET->write(b.buf, b.length);
  b.reset();
  return deserializeInt(RPCPROXYSOCKET);
}

int subtract(int x, int y) {
  return remoteProcedureCall("subtract", x, y);
}

int divide(int x, int y) {
  return remoteProcedureCall("divide", x, y);
}

int add(int x, int y) {
  return remoteProcedureCall("add", x, y);
}

int multiply(int x, int y) {
  return remoteProcedureCall("multiply", x, y);
}
