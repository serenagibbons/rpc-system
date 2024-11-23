// --------------------------------------------------------------
//
//                        arithmetic.cpp
//
//        Author: Noah Mendelsohn         
//   
//
//        Trivial implementations of the routines declared
//        in arithmetic.idl. These are for testing: they
//        just print messages.
//
//       Copyright: 2012 Noah Mendelsohn
//     
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include "arithmetic.idl"

#include <cstdio>

int add(int x, int y) {
  printf("add() invoked\n");
  return x+y;
}

int subtract(int x, int y) {
  printf("subtract() invoked\n");
  return x-y;
}

int multiply(int x, int y) {
  printf("multiply() invoked\n");
  return x*y;
}

int divide(int x, int y) {
  printf("divide() invoked\n");
  return x/y;
}

