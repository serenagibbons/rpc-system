// --------------------------------------------------------------
// File: structs.stub.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "structs.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace C150NETWORK;

void serialize(Buffer *b, ThreePeople T1);
void deserializeThreePeople(ThreePeople *T1);
void serialize(Buffer *b, Person P1);
void deserializePerson(Person *P1);
void serialize(Buffer *b, rectangle r1);
void deserializeRectangle(rectangle *r1);

void serialize(Buffer *b, ThreePeople T1) {
	serialize(b, T1.p1);
	serialize(b, T1.p2);
	serialize(b, T1.p3);
}

void serialize(Buffer *b, Person P1) {
	serialize(b, P1.firstname);
	serialize(b, P1.lastname);
	serialize(b, P1.age);
}

void serialize(Buffer *b, rectangle r1) {
	serialize(b, r1.x);
	serialize(b, r1.y);
}

void deserializeThreePeople(ThreePeople *T1) {
	deserializePerson(&(T1->p1));
	deserializePerson(&(T1->p2));
	deserializePerson(&(T1->p3));
}

void deserializePerson(Person *P1) {
	P1->firstname = deserializeString(RPCSTUBSOCKET);
	P1->lastname = deserializeString(RPCSTUBSOCKET);
	P1->age = deserializeInt(RPCSTUBSOCKET);
}

void deserializeRectangle(rectangle *r1) {
	r1->x = deserializeInt(RPCSTUBSOCKET);
	r1->y = deserializeInt(RPCSTUBSOCKET);
}

void __findPerson(ThreePeople tp) {
	Person res = findPerson(tp);
	Buffer b;
	serialize(&b, res);
	RPCSTUBSOCKET->write(b.buf, b.length);
}

void __area(rectangle r) {
	int res = area(r);
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

  if (func_name == "findPerson") {
    ThreePeople tp;
		deserializeThreePeople(&(tp));
		__findPerson(tp);
  } 
  else if (func_name == "area") {
    rectangle r;
    deserializeRectangle(&(r));
		__area(r);  
  }
  else {
    __badFunction(func_name.c_str());
    printf("Unknown function: %s\n", func_name.c_str());
  }
}