// --------------------------------------------------------------
// File: deserializer.h
// Author: Serena GIbbons
// --------------------------------------------------------------

#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "rpcproxyhelper.h"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
using namespace std;

#define SIZE 4

// Function declarations
int deserializeInt(C150StreamSocket *rpcSocket);
float deserializeFloat(C150StreamSocket *rpcSocket);
string deserializeString(C150StreamSocket *rpcSocket);

// Function implementations
int deserializeInt(C150StreamSocket *rpcSocket) {
    char buf[SIZE];
    int result;
    int readlen = rpcSocket->read(buf, SIZE);
    if (readlen == 0)
        return 0; 
    memcpy(&result, buf, SIZE);
    int ntohl_result = ntohl(result);
    *GRADING << "Deserializing int result = " << ntohl_result << endl;
    return ntohl_result;
}

float deserializeFloat(C150StreamSocket *rpcSocket) {
	string s = deserializeString(rpcSocket);
	if (s.compare("")==0) {
		return -1;
	} 
    float result = atof(s.c_str());
    *GRADING << "Deserializing float result = " << result << endl;
	return result;
}

string deserializeString(C150StreamSocket *rpcSocket) {
    int length = deserializeInt(rpcSocket);
    char buf[length];
    int readlen = rpcSocket->read(buf, length);
    if (readlen == 0) 
        return "";
    string result(buf, length);
    *GRADING << "Deserializing string result = " << result << endl;
    return result;
}

#endif  // DESERIALIZER_H