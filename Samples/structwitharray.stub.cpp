#include <string>
using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "structwitharray.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"
using namespace C150NETWORK;
void serializes(Buffer *b, s s1);
void serialize__int_4_10_100_(Buffer *b, int arr[4][10][100]);
void serialize__int_10_100_(Buffer *b, int arr[10][100]);
void serialize__int_4_(Buffer *b, int arr[4]);
void serialize__int_10_(Buffer *b, int arr[10]);
void serialize__int_100_(Buffer *b, int arr[100]);
void serialize__int_4_10_(Buffer *b, int arr[4][10]);
void deserializes (s *s1);
void deserialize__int_4_10_100_(int arr[4][10][100]);
void deserialize__int_10_100_(int arr[10][100]);
void deserialize__int_4_(int arr[4]);
void deserialize__int_10_(int arr[10]);
void deserialize__int_100_(int arr[100]);
void deserialize__int_4_10_(int arr[4][10]);
void serializes(Buffer *b, s s1) {
	serialize__int_4_(b, s1.m1);
	serialize__int_4_10_(b, s1.m2);
	serialize__int_4_10_100_(b, s1.m3);
}
void serialize__int_4_10_100_(Buffer *b, int arr[4][10][100]) {
	for (int i0 = 0; i0 < 4; i0++) {
		for (int i1 = 0; i1 < 10; i1++) {
			for (int i2 = 0; i2 < 100; i2++) {
				serialize(b, arr[i0][i1][i2]);
			}
		}
	}
}
void serialize__int_10_100_(Buffer *b, int arr[10][100]) {
	for (int i0 = 0; i0 < 10; i0++) {
		for (int i1 = 0; i1 < 100; i1++) {
			serialize(b, arr[i0][i1]);
		}
	}
}
void serialize__int_4_(Buffer *b, int arr[4]) {
	for (int i0 = 0; i0 < 4; i0++) {
		serialize(b, arr[i0]);
	}
}
void serialize__int_10_(Buffer *b, int arr[10]) {
	for (int i0 = 0; i0 < 10; i0++) {
		serialize(b, arr[i0]);
	}
}
void serialize__int_100_(Buffer *b, int arr[100]) {
	for (int i0 = 0; i0 < 100; i0++) {
		serialize(b, arr[i0]);
	}
}
void serialize__int_4_10_(Buffer *b, int arr[4][10]) {
	for (int i0 = 0; i0 < 4; i0++) {
		for (int i1 = 0; i1 < 10; i1++) {
			serialize(b, arr[i0][i1]);
		}
	}
}
void deserializes (s *s1) {
	deserialize__int_4_(s1->m1);
	deserialize__int_4_10_(s1->m2);
	deserialize__int_4_10_100_(s1->m3);
}
void deserialize__int_4_10_100_(int arr[4][10][100]) {
	for (int idx0 = 0; idx0 < 4; idx0++) {
		for (int idx1 = 0; idx1 < 10; idx1++) {
			for (int idx2 = 0; idx2 < 100; idx2++) {
				arr[idx0][idx1][idx2] = deserializeInt(RPCSTUBSOCKET);
			}
		}
	}
}
void deserialize__int_10_100_(int arr[10][100]) {
	for (int idx0 = 0; idx0 < 10; idx0++) {
		for (int idx1 = 0; idx1 < 100; idx1++) {
			arr[idx0][idx1] = deserializeInt(RPCSTUBSOCKET);
		}
	}
}
void deserialize__int_4_(int arr[4]) {
	for (int idx0 = 0; idx0 < 4; idx0++) {
		arr[idx0] = deserializeInt(RPCSTUBSOCKET);
	}
}
void deserialize__int_10_(int arr[10]) {
	for (int idx0 = 0; idx0 < 10; idx0++) {
		arr[idx0] = deserializeInt(RPCSTUBSOCKET);
	}
}
void deserialize__int_100_(int arr[100]) {
	for (int idx0 = 0; idx0 < 100; idx0++) {
		arr[idx0] = deserializeInt(RPCSTUBSOCKET);
	}
}
void deserialize__int_4_10_(int arr[4][10]) {
	for (int idx0 = 0; idx0 < 4; idx0++) {
		for (int idx1 = 0; idx1 < 10; idx1++) {
			arr[idx0][idx1] = deserializeInt(RPCSTUBSOCKET);
		}
	}
}
void __getSumOfm1(s s1) {
	*GRADING << "Invoking getSumOfm1(s s1)." << endl;
	int result = getSumOfm1(s1);
	*GRADING << "Returned from getSumOfm1(s s1). Responding to client." << endl;
	Buffer b;
	serialize(&b, result);
	RPCSTUBSOCKET->write(b.buf, b.length);
	b.reset();
}
void dispatchFunction() {
	if (!RPCSTUBSOCKET->eof()) {
		string func_name = deserializeString(RPCSTUBSOCKET);
		if (func_name.compare("") == 0) return;
		else if (func_name == "getSumOfm1") {
			s s1;
			deserializes(&(s1));
			__getSumOfm1(s1);
		}
		else {
			throw C150Exception("Error: invalid function.");
		}
	}
}
