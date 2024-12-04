// --------------------------------------------------------------
// File: floatarithmetic.stub.cpp
// Author: Serena Gibbons
// --------------------------------------------------------------

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include "floatarithmetic.idl"
#include "rpcstubhelper.h"
#include "c150debug.h"
#include "buffer.h"
#include "serializer.h"
#include "deserializer.h"

using namespace std;
using namespace C150NETWORK;

void __divide(float x, float y) {
    float res = divide(x, y);
    struct Buffer b;
    b.buf = (char*) malloc(1);
    b.length = 0;
    serialize(&b, res);
    RPCSTUBSOCKET->write(b.buf, b.length);
}

void __multiply(float x, float y) {
    float res = multiply(x, y);
    struct Buffer b;
    b.buf = (char*) malloc(1);
    b.length = 0;
    serialize(&b, res);
    RPCSTUBSOCKET->write(b.buf, b.length);
}

void __subtract(float x, float y) {
    float res = subtract(x, y);
    struct Buffer b;
    b.buf = (char*) malloc(1);
    b.length = 0;
    serialize(&b, res);
    RPCSTUBSOCKET->write(b.buf, b.length);
}

void __add(float x, float y) {
    float res = add(x, y);
    struct Buffer b;
    b.buf = (char*) malloc(1);
    b.length = 0;
    serialize(&b, res);
    RPCSTUBSOCKET->write(b.buf, b.length);
}

void __badFunction(const char *functionName) {
    char doneBuffer[5] = "BAD";
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void dispatchFunction() {
  if (!RPCSTUBSOCKET->eof()) {
      string func_name = deserializeString(RPCSTUBSOCKET);
      if (func_name.compare("") == 0) 
          return;
      else if (func_name == "divide") {
          float x = deserializeFloat(RPCSTUBSOCKET);
          float y = deserializeFloat(RPCSTUBSOCKET);
          __divide(x, y);
      }
      else if (func_name == "multiply") {
          float x = deserializeFloat(RPCSTUBSOCKET);
          float y = deserializeFloat(RPCSTUBSOCKET);
          __multiply(x, y);
      }
      else if (func_name == "subtract") {
          float x = deserializeFloat(RPCSTUBSOCKET);
          float y = deserializeFloat(RPCSTUBSOCKET);
          __subtract(x, y);
      }
      else if (func_name == "add") {
          float x = deserializeFloat(RPCSTUBSOCKET);
          float y = deserializeFloat(RPCSTUBSOCKET);
          __add(x, y);
      }
      else {
          printf("BAD FUNCTION");
      }
    }
}


/*
#include "floatarithmetic.idl"
#include "rpcstubhelper.h"
#include <cstdio>
#include <cstring>
#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

void getFunctionNamefromStream();

// ======================================================================
//                             STUBS
//
//    Each of these is generated to match the signature of the 
//    function for which it is a stub. The names are prefixed with "__"
//    to keep them distinct from the actual routines, which we call!
//
//    Note that when functions take arguments, these are the routines
//    that will read them from the input stream. These routines should
//    be generated dynamically from your rpcgen program (and so should the
//    code above).
//
// ======================================================================
  


float __add(float x, float y) {
  char doneBuffer[5] = "DONE";  // to write magic value DONE + null
  float result;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: invoking add()");
  result = add(x, y);

  //
  // Send the response to the client
  //
  // If add returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: returned from  add() -- responding to client");
  RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

  return result;
}

float __subtract(float x, float y) {
  char doneBuffer[5] = "DONE";  // to write magic value DONE + null
  float result;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: invoking subtract()");
  result = subtract(x, y);

  //
  // Send the response to the client
  //
  // If func2 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: returned from  subtract() -- responding to client");
  RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

  return result;
}

float __multiply(float x, float y) {
  char doneBuffer[5] = "DONE";  // to write magic value DONE + null
  float result;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: invoking multiply()");
  result = multiply(x, y);

  //
  // Send the response to the client
  //
  // If func3 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: returned from  multiply() -- responding to client");
  RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

  return result;
}

float __divide(float x, float y) {
  char doneBuffer[5] = "DONE";  // to write magic value DONE + null
  float result;
  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: invoking divide()");
  result = divide(x, y);

  //s
  // Send the response to the client
  //
  // If func3 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: returned from  divide() -- responding to client");
  RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

  return result;
}


//
//     __badFunction
//
//   Pseudo-stub for missing functions.
//

void __badFunction(char *functionName) {
  char doneBuffer[5] = "BAD";  // to write magic value DONE + null


  //
  // Send the response to the client indicating bad function
  //

  c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub.cpp: received call for nonexistent function %s()",functionName);
  RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}



// ======================================================================
//
//                        COMMON SUPPORT FUNCTIONS
//
// ======================================================================

// forward declaration
void getFunctionNameFromStream(char *buffer, unsigned int bufSize);



//
//                         dispatchFunction()
//
//   Called when we're ready to read a new invocation request from the stream
//

void dispatchFunction() {


  char functionNameBuffer[50];

  //
  // Read the function name from the stream -- note
  // REPLACE THIS WITH YOUR OWN LOGIC DEPENDING ON THE 
  // WIRE FORMAT YOU USE
  //
  getFunctionNameFromStream(functionNameBuffer,sizeof(functionNameBuffer));

  //
  // We've read the function name, call the stub for the right one
  // The stub will invoke the function and send response.
  //

  if (!RPCSTUBSOCKET-> eof()) {
    if (strcmp(functionNameBuffer,"add") == 0)
      __add(10.0,3.5);
    else   if (strcmp(functionNameBuffer,"subtract") == 0)
      __subtract(10.0,3.5);
    else   if (strcmp(functionNameBuffer,"multiply") == 0)
      __multiply(10,3.5);
    else   if (strcmp(functionNameBuffer,"divide") == 0)
      __divide(10,3.5);
    else
      __badFunction(functionNameBuffer);
  }
}

 
//
//                   getFunctionNamefromStream
//
//   Helper routine to read function name from the stream. 
//   Note that this code is the same for all stubs, so can be generated
//   as boilerplate.
//
//   Important: this routine must leave the sock open but at EOF
//   when eof is read from client.
//
void getFunctionNameFromStream(char *buffer, unsigned int bufSize) {
  unsigned int i;
  char *bufp;    // next char to read
  bool readnull;
  ssize_t readlen;             // amount of data read from socket
  
  //
  // Read a message from the stream
  // -1 in size below is to leave room for null
  //
  readnull = false;
  bufp = buffer;
  for (i=0; i< bufSize; i++) {
    readlen = RPCSTUBSOCKET-> read(bufp, 1);  // read a byte
    // check for eof or error
    if (readlen == 0) {
      break;
    }
    // check for null and bump buffer pofloater
    if (*bufp++ == '\0') {
      readnull = true;
      break;
    }
  }
  
  //
  // With TCP streams, we should never get a 0 length read
  // except with timeouts (which we're not setting in pingstreamserver)
  // or EOF
  //
  if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub: read zero length message, checking EOF");
    if (RPCSTUBSOCKET-> eof()) {
      c150debug->printf(C150RPCDEBUG,"floatarithmetic.stub: EOF signaled on input");

    } else {
      throw C150Exception("floatarithmetic.stub: unexpected zero length read without eof");
    }
  }

  //
  // If we didn't get a null, input message was poorly formatted
  //
  else if(!readnull) 
    throw C150Exception("floatarithmetic.stub: method name not null terminated or too long");

  
  //
  // Note that eof may be set here for our caller to check
  //

}


*/