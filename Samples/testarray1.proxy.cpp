// --------------------------------------------------------------
// File: testarray1.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "testarray1.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
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
		arr[i] = deserializeInt(RPCPROXYSOCKET);
	}
}

void serialize(Buffer *b, float arr[10]) {
	for (int i = 0; i < 10; i++) {
		serialize(b, arr[i]);
	}
}

void deserialze__float_10__(float arr[10]) {
	for (int i = 0; i < 10; i++) {
		arr[i] = deserializeFloat(RPCPROXYSOCKET);
	}
}

int sqrt(int x[24], int y[24]) {
	Buffer b;
	serialize(&b, "sqrt");
	serialize(&b, x);
	serialize(&b, y);
	RPCPROXYSOCKET->write(b.buf, b.length);
	int result = deserializeInt(RPCPROXYSOCKET);
	return result;
}

float add(float x[10]) {
    Buffer b;
	serialize(&b, "add");
	serialize(&b, x);
	RPCPROXYSOCKET->write(b.buf, b.length);
	float result = deserializeFloat(RPCPROXYSOCKET);
	return result;
}