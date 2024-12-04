// --------------------------------------------------------------
// File: floatarithmetic.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "floatarithmetic.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
using namespace C150NETWORK;

// RPC Function Implementation
float remoteProcedureCall(const string &functionName, float x, float y) {
  Buffer b;
  serialize(&b, functionName);
  serialize(&b, x);
  serialize(&b, y);
  RPCPROXYSOCKET->write(b.buf, b.length);
  b.reset();
  return deserializeFloat(RPCPROXYSOCKET);
}

float subtract(float x, float y) {
  return remoteProcedureCall("subtract", x, y);
}

float divide(float x, float y) {
  return remoteProcedureCall("divide", x, y);
}

float add(float x, float y) {
  return remoteProcedureCall("add", x, y);
}

float multiply(float x, float y) {
  return remoteProcedureCall("multiply", x, y);
}