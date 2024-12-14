// --------------------------------------------------------------
// File: testarray1.stub.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "testarray1.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace C150NETWORK;


void serialize(Buffer *b, int arr[24]);
void deserialze__int_24__(int arr[24]);
void serialize(Buffer *b, float arr[10]);
void deserialze__float_10__(float arr[10]);

void serialize(Buffer *b, int arr[24]) {
	for (int i = 0; i < 24; i++) {
		serialize(b, arr[i]);
	}
}

void deserialze__int_24__(int arr[24]) {
	for (int i = 0; i < 24; i++) {
		arr[i] = deserializeInt(RPCSTUBSOCKET);
	}
}

void serialize(Buffer *b, float arr[10]) {
	for (int i = 0; i < 10; i++) {
		serialize(b, arr[i]);
	}
}

void deserialze__float_10__(float arr[10]) {
	for (int i = 0; i < 10; i++) {
		arr[i] = deserializeFloat(RPCSTUBSOCKET);
	}
}

void __sqrt(int x[24], int y[24]) {
	int res = sqrt(x, y);
	Buffer b;
	serialize(&b, res);
	RPCSTUBSOCKET->write(b.buf, b.length);
}

void __add(float x[10]) {
	float res = add(x);
	Buffer b;
	serialize(&b, res);
	RPCSTUBSOCKET->write(b.buf, b.length);
}

void __badFunction(const char *functionName) {
	char doneBuffer[5] = "BAD";
	RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

// Dispatcher Function
void dispatchFunction() {
  if (RPCSTUBSOCKET->eof()) 
    return;

  string func_name = deserializeString(RPCSTUBSOCKET);
  if (func_name.empty()) 
    return;

  if (func_name == "sqrt") {
    int x[24];
    int y[24];
	deserialze__int_24__(x);
	deserialze__int_24__(y);
	__sqrt(x, y);
  } 
  else if (func_name == "add") {
	float z[24];
	deserialze__float_10__(z);
	__add(z);
  }
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}