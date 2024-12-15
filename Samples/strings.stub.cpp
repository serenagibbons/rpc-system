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

void serialize__string_3_(Buffer *b, string arr[3]);
void deserialize__string_3_(string arr[3]);

void serialize__string_3_(Buffer *b, string arr[3]) {
	for (int i0 = 0; i0 < 3; i0++) {
		serialize(b, arr[i0]);
	}
}
void deserialize__string_3_(string arr[3]) {
	for (int idx0 = 0; idx0 < 3; idx0++) {
		arr[idx0] = deserializeString(RPCSTUBSOCKET);
	}
}

// Strings Function Handlers
void __concat(string s1, string s2) {
  string result = concat(s1, s2);
  Buffer b;
  serialize(&b, result);
  RPCSTUBSOCKET->write(b.buf, b.length);
  b.reset();
}

// Strings Function Handlers
void __printStringArray(string arr[3]) {
  *GRADING << "Invoking printStringArray()." << endl;
  printStringArray(arr);
  *GRADING << "Returned from func2(). Responding to client." << endl;
	string result = "DONE";
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
  else if (func_name == "printStringArray") {
    string arr[3];
    deserialize__string_3_(arr);
    __printStringArray(arr);
  }
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}
