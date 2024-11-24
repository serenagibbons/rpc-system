// --------------------------------------------------------------
//
//                        strings.proxy.cpp
//
//       Author: Serena GIbbons
//
//       This is a hand-crafted demonstration proxy.
//
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>
#include "c150debug.h"

#include <string>
using namespace std;

#include "strings.idl"

using namespace C150NETWORK;  // for all the comp150 utilities 

string concat(string s1, string s2) {
  char readBuffer[5];  // to read magic value DONE + null
  //
  // Send the Remote Call
  //
  c150debug->printf(C150RPCDEBUG,"strings.proxy.cpp: concat() invoked");
  RPCPROXYSOCKET->write("concat", strlen("concat")+1); // write function name including null
  //
  // Read the response
  //
  c150debug->printf(C150RPCDEBUG,"strings.proxy.cpp: concat() invocation sent, waiting for response");
  RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE

  //
  // Check the response
  //
  if (strncmp(readBuffer,"DONE", sizeof(readBuffer))!=0) {
    throw C150Exception("strings.proxy: concat() received invalid response from the server");
  }
  c150debug->printf(C150RPCDEBUG,"strings.proxy.cpp: concat() successful return from remote call");
  return s1 + s2;
}
