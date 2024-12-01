#ifndef SERIALIZER_H
#define SERIALIZER_H

#endif  // SERIALIZER_H

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
void serializeInt(Buffer *b, int i);
void serializeString(Buffer *b, const string &s);

// Function implementations
void serializeInt(Buffer *b, int i) {
  int converted = htonl(i);
  int length = b->length + SIZE;
  char *newBuf = (char *)malloc(length);
  memcpy(newBuf, b->buf, b->length);
  memcpy(newBuf + b->length, &converted, SIZE);
  b->reset();
  b->buf = newBuf;
  b->length = length;
}

void serializeString(Buffer *b, const string &s) {
  serializeInt(b, s.length());
  int length = b->length + s.length();
  char *newBuf = (char *)malloc(length);
  memcpy(newBuf, b->buf, b->length);
  memcpy(newBuf + b->length, s.c_str(), s.length());
  b->reset();
  b->buf = newBuf;
  b->length = length;
}