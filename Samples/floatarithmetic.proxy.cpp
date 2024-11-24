// --------------------------------------------------------------
//
//                        floatarithmetic.proxy.cpp
//
//       Author: Serena Gibbons       
//   
//       This is a hand-crafted demonstration proxy.
//
//       For your project, your "rpcgen" program will generate
//       proxies like this one automatically from the idl
//       file. Note that this proxy also #includes the 
//       floatarithmetic.idl file. Of course, your rpcgen
//       program will change that, as well as the number
//       of functions generated. More importantly, it will
//       generate code to handle function arguments and
//       return values.
//  
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include "floatarithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>
#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

float add(float x, float y) {
  char readBuffer[5];  // to read magic value DONE + null
  //
  // Send the Remote Call
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: add() invoked");
  RPCPROXYSOCKET->write("add", strlen("add")+1); // write function name including null
  //
  // Read the response
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: add() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer))!=0) {
    throw C150Exception("floatarithmetic.proxy: add() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: add() successful return from remote call");
  return x+y;
}

float subtract(float x, float y) {
      char readBuffer[5];  // to read magic value DONE + null
  //
  // Send the Remote Call
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: subtract() invoked");
  RPCPROXYSOCKET->write("subtract", strlen("subtract")+1); // write function name including null
  //
  // Read the response
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: subtract() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer))!=0) {
    throw C150Exception("floatarithmetic.proxy: subtract() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: subtract() successful return from remote call");
  return x-y;
}

float multiply(float x, float y) {
      char readBuffer[5];  // to read magic value DONE + null
  //
  // Send the Remote Call
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: multiply() invoked");
  RPCPROXYSOCKET->write("multiply", strlen("multiply")+1); // write function name including null
  //
  // Read the response
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: multiply() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer))!=0) {
    throw C150Exception("floatarithmetic.proxy: multiply() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: multiply() successful return from remote call");
  return x*y;
}

float divide(float x, float y) {
      char readBuffer[5];  // to read magic value DONE + null
  //
  // Send the Remote Call
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: divide() invoked");
  RPCPROXYSOCKET->write("divide", strlen("divide")+1); // write function name including null
  //
  // Read the response
  //
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: divide() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer))!=0) {
    throw C150Exception("floatarithmetic.proxy: divide() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"floatarithmetic.proxy.cpp: divide() successful return from remote call");
  return x/y;
}