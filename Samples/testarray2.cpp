// --------------------------------------------------------------
//
//                        testarray2.cpp
//
//        Author: Serena Gibbons 
//   
//
//        Trivial implementations of the routines declared
//        in testarray1.idl. These are for testing: they
//        just print messages.
//
//     
// --------------------------------------------------------------
#include "testarray2.idl" 

#include <cmath>
#include <cstdio>

int sqrt(int x[24], int y[24][15], int z[24][15]) {
    printf("sqrt() invoked\n");
    int res = x[23] + y[23][14] + z[23][14];
    return sqrt(res);
}