// --------------------------------------------------------------
// File: testarray2.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "testarray2.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
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

void deserialze__int_24__(int arr[24]) {
	for (int i = 0; i < 24; i++) {
		arr[i] = deserializeInt(RPCPROXYSOCKET);
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
			arr[i][j] = deserializeInt(RPCPROXYSOCKET);
		}
	}
}

int sqrt(int x[24], int y[24][15], int z[24][15]) {
	Buffer b;
	serialize(&b, "sqrt");
	serialize__int_24__(&b, x);
	serialize__int_24_15__(&b, y);
	serialize__int_24_15__(&b, z);
	RPCPROXYSOCKET->write(b.buf, b.length);
	int result = deserializeInt(RPCPROXYSOCKET);
	return result;
}