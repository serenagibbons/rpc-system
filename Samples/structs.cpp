// --------------------------------------------------------------
//
//                        structs.cpp
//
//        Author: Serena Gibbons 
//   
//
//        Trivial implementations of the routines declared
//        in structs.idl. These are for testing: they
//        just print messages.
//
//     
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include <cstdio>
#include <string>
using namespace std;

#include "structs.idl"

Person findPerson(ThreePeople tp) {
    printf("findPerson() invoked\n");
    return tp.p1;
}

int area(rectangle r) {
    printf("area() invoked\n");
    return r.x * r.y; 
}

Point calculateDistance(Point p1, Point p2) {
    printf("calculateDistance() invoked\n");
    int x = p1.x - p2.x;
    int y = p2.y - p2.y;
    Point p = {x, y};
    return p;
}

void searchRectangles(rectangle rects[10]) {
    printf("searchRectangles() invoked\n");
    for (int i = 0; i < 10; ++i) {
        printf("rectangle %d; ", i);
    }
}