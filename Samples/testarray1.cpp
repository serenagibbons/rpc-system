// --------------------------------------------------------------
//
//                        testarray1.cpp
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
#include "testarray1.idl" 

#include <cmath>
#include <cstdio>

int sqrt(int x[24], int y[24]) {
    printf("sqrt() invoked\n");
    int res = 0;
    for (int i=0; i<24; i++) {
        res += x[i] + y[i];
    }
    return sqrt(res);
}

float add(float x[10]) {
    printf("add() invoked\n");
    float res = 0;
    for (int i=0; i<10; i++) {
        res += x[i];
    }
    return res;
}