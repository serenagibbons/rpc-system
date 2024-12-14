// --------------------------------------------------------------
// File: testarray2.stub.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "testarray2.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace C150NETWORK;

void serialize__int_24__(Buffer *b, int arr[24]);
void deserialze__int_24__(int arr[24]);
void serialize__int_24_15__(Buffer *b, int arr[24][15]);
void deserialize__int_24_15__(int arr[24][15]);


void serialize__int_24__(Buffer *b, int arr[24]) {
	for (int i = 0; i < 24; i++) {
		serialize(b, arr[i]);
	}
}

void deserialize__int_24__(int arr[24]) {
	for (int i = 0; i < 24; i++) {
		arr[i] = deserializeInt(RPCSTUBSOCKET);
	}
}

void serialize__int_24_15__(Buffer *b, int arr[24][15]) {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 15; j++) {
			serialize(b, arr[i][j]);
		}
	}
}

void deserialize__int_24_15__(int arr[24][15]) {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 15; j++) {
			arr[i][j] = deserializeInt(RPCSTUBSOCKET);
		}
	}
}

void __sqrt(int x[24], int y[24][15], int z[24][15]) {
	int res = sqrt(x, y, z);
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
    int y[24][15];
    int z[24][15];
	deserialize__int_24__(x);
	deserialize__int_24_15__(y);
	deserialize__int_24_15__(z);
	
	printf("x[23] = %d\n", x[23]);
    printf("y[23][14] = %d\n", y[23][14]);
    printf("z[23][14] = %d\n", z[23][14]);

	__sqrt(x, y, z);
  } 
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}