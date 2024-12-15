// --------------------------------------------------------------
// File: serializer.h
// Author: Serena GIbbons
// --------------------------------------------------------------

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "c150debug.h"
#include "buffer.h"
using namespace std;

#define SIZE 4

// Function declarations
void serialize(Buffer *b, int i);
void serialize(Buffer *b, float f);
void serialize(Buffer *b, const string &s);

// Function implementations
void serialize(Buffer *b, int i) {
    *GRADING << "Serializing int " << i << endl;
    int networkByteOrder = htonl(i);
    int length = b->length + SIZE;
    char *newBuf = (char *)malloc(length);
    memcpy(newBuf, b->buf, b->length);
    memcpy(newBuf + b->length, &networkByteOrder, SIZE);
    b->reset();
    b->buf = newBuf;
    b->length = length;
}

void serialize(Buffer *b, float f) {
    *GRADING << "Serializing float " << f << endl;
	string s = to_string(f);
	serialize(b, static_cast<int>(s.length()));
    int length = b->length + s.length();
    char *newBuf = (char *)malloc(length);
    memcpy(newBuf, b->buf, b->length);
    memcpy(newBuf + b->length, s.c_str(), s.length());
    b->reset();
    b->buf = newBuf;
    b->length = length;
}

void serialize(Buffer *b, const string &s) {
    *GRADING << "Serializing string " << s << endl;
	serialize(b, static_cast<int>(s.length()));
    int length = b->length + s.length();
    char *newBuf = (char *)malloc(length);
    memcpy(newBuf, b->buf, b->length);
    memcpy(newBuf + b->length, s.c_str(), s.length());
    b->reset();
    b->buf = newBuf;
    b->length = length;
}

#endif  // SERIALIZER_H