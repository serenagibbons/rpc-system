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

void serialize__string_3_(Buffer *b, string arr[3]);
void deserialize__string_3_(string arr[3]);

void serialize__string_3_(Buffer *b, string arr[3]) {
	for (int i0 = 0; i0 < 3; i0++) {
		serialize(b, arr[i0]);
	}
}
void deserialize__string_3_(string arr[3]) {
	for (int idx0 = 0; idx0 < 3; idx0++) {
		arr[idx0] = deserializeString(RPCPROXYSOCKET);
	}
}

string concat(string s1, string s2) {
	Buffer b;
	serialize(&b, "concat");
	serialize(&b, s1);
	serialize(&b, s2);
	*GRADING << "concat(string s1, string s2) invoked." << endl;
	RPCPROXYSOCKET->write(b.buf, b.length);
	b.reset();
	string result = deserializeString(RPCPROXYSOCKET);
	return result;
}

void printStringArray(string arr[3]) {
	Buffer b;
	serialize(&b, "printStringArray");
	serialize__string_3_(&b, arr);
	*GRADING << "printStringArray(string arr[3]) invoked." << endl;
	RPCPROXYSOCKET->write(b.buf, b.length);
	b.reset();
	string result = deserializeString(RPCPROXYSOCKET);
  *GRADING << "Result from printStringArray(string arr[3])" << result << endl;
	if (result.compare("DONE") != 0) {
		throw C150Exception("printStringArray() received invalid response from the server");
	}

}