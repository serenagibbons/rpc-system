// --------------------------------------------------------------
// File: structs.proxy.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "structs.idl"
#include "rpcproxyhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
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

void serialize(Buffer *b, Point P1) {
	serialize(b, P1.x);
	serialize(b, P1.y);
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
	P1->firstname = deserializeString(RPCPROXYSOCKET);
	P1->lastname = deserializeString(RPCPROXYSOCKET);
	P1->age = deserializeInt(RPCPROXYSOCKET);
}

void deserializeRectangle(rectangle *r1) {
	r1->x = deserializeInt(RPCPROXYSOCKET);
	r1->y = deserializeInt(RPCPROXYSOCKET);
}

void deserializePoint(Point *P1) {
	r1->x = deserializeInt(RPCPROXYSOCKET);
	r1->y = deserializeInt(RPCPROXYSOCKET);
}

Person findPerson(ThreePeople tp) {
	Buffer b;
	serialize(&b, "findPerson");
	serialize(&b, tp);
	*GRADING << "findPerson invoked" << endl;
	RPCPROXYSOCKET->write(b.buf, b.length);
	Person res;
	deserializePerson(&res);
	return res;
}

int area(rectangle r) {
	Buffer b;
	serialize(&b, "area");
	serialize(&b, r);
	*GRADING << "area invoked" << endl;
	RPCPROXYSOCKET->write(b.buf, b.length);
	return deserializeInt(RPCPROXYSOCKET);
}

Point calculateDistance(Point point1, Point point2) {
	Buffer b;
	serialize(&b, "calculateDistance");
	serialize(&b, point1);
	serialize(&b, point2);
	*GRADING << "calculateDistance invoked" << endl;
	RPCPROXYSOCKET->write(b.buf, b.length);
	Point res;
	deserializePerson(&res);
	return res;
}