#ifndef SERIALIZER_H
#define SERIALIZER_H

#endif  // SERIALIZER_H

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
string deserializeString(C150StreamSocket *rpcSocket);

// Function implementations
int deserializeInt(C150StreamSocket *rpcSocket) {
  char buf[SIZE];
  int result;
  int readlen = rpcSocket->read(buf, SIZE);

  // Handle end of file
  if (readlen == 0) 
    return 0; 
    
  memcpy(&result, buf, SIZE);
  return ntohl(result);
}

string deserializeString(C150StreamSocket *rpcSocket) {
  int length = deserializeInt(rpcSocket);
	char buf[length];
	int readlen = rpcSocket->read(buf, length);
	if (readlen == 0) 
    return "";
	string result(buf, length);
	return result;
}

// Function declarations
int deserializeInt();
string deserializeString();

int deserializeInt() {
  char buf[SIZE];
	int res;
	int readlen = RPCSTUBSOCKET->read(buf, SIZE);
	if (readlen == 0) 
    return 0;
	memcpy(&res, buf, SIZE);
	return ntohl(res);
}

string deserializeString() {
  int length = deserializeInt();

  // Handle empty string 
  if (length <= 0) 
    return "";

  char buf[length];
  int readlen = RPCSTUBSOCKET->read(buf, length);

  // Handle end of file
  if (readlen == 0) 
    return ""; 

  return string(buf, length);
}