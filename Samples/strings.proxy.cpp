// --------------------------------------------------------------
// File: strings.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "strings.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
using namespace C150NETWORK;

// RPC Function Implementation
string remoteProcedureCall(const string &functionName, string s1, string s2) {
  Buffer b;
  serialize(&b, functionName);
  serialize(&b, s1);
  serialize(&b, s2);
  RPCPROXYSOCKET->write(b.buf, b.length);
  b.reset();
  return deserializeString(RPCPROXYSOCKET);
}

string concat (string s1, string s2) {
  return remoteProcedureCall("concat", s1, s2);
}