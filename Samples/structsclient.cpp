// --------------------------------------------------------------
//
//                        structsclient.cpp
//
//        Author: Serena Gibbons  
//   
//
//        This is a test program designed to call a few demonstration
//        functions, after first enabling the COMP 150-IDS rpcproxyhelper.
//        (The purpose of the helper is to open a TCP stream connection
//        to the proper server, and to leave the socket pointer where
//        the generated proxies can find it.
//
//        COMMAND LINE
//
//              structsclient <servername> 
//
//     
// --------------------------------------------------------------


// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE REMOTING. OF COURSE, THE PARTICULAR IDL FILE
// IS CHOSEN ACCORDING TO THE TEST OR APPLICATION
// 
// NOTE THAT THIS IS THE SAME IDL FILE INCLUDED WITH THE PROXIES
// AND STUBS, AND ALSO USED AS INPUT TO AUTOMATIC PROXY/STUB
// GENERATOR PROGRAM

#include "rpcproxyhelper.h"

#include "c150debug.h"
#include "c150grading.h"
#include <fstream>
#include <string>

using namespace std;          // for C++ std library
#include "structs.idl"

using namespace C150NETWORK;  // for all the comp150 utilities 

// forward declarations
void setUpDebugLogging(const char *logname, int argc, char *argv[]);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                    Command line arguments
//
// The following are used as subscripts to argv, the command line arguments
// If we want to change the command line syntax, doing this
// symbolically makes it a bit easier.
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

const int serverArg = 1;     // server name is 1st arg


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                           main program
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
int 
main(int argc, char *argv[]) {

     //
     //  Set up debug message logging
     //
     setUpDebugLogging("structsclientdebug.txt",argc, argv);

     //
     // Make sure command line looks right
     //
     if (argc != 2) {
       fprintf(stderr,"Correct syntxt is: %s <servername> \n", argv[0]);
       exit(1);
     }

     //
     //  DO THIS FIRST OR YOUR ASSIGNMENT WON'T BE GRADED!
     //
     
     GRADEME(argc, argv);

     //
     //     Call the functions and see if they return
     //
     try {
        //
        // Set up the socket so the proxies can find it
        //
        rpcproxyinitialize(argv[serverArg]);

        Person personResult;

        // Creating some sample people
        Person person1 = {"John", "Doe", 25};
        Person person2 = {"Jane", "Smith", 30};
        Person person3 = {"Emily", "Jones", 22};

        // Grouping them into ThreePeople
        ThreePeople tp = {person1, person2, person3};
        // 
        // Call (possibly remote) concat
        //
        printf("Calling findPerson(tp)\n");
        *GRADING << "Calling findPerson(tp)." << endl;
        personResult = findPerson(tp);                  
        printf("Returned from findPerson(tp). Result: %s %s, Age: %d\n", 
                personResult.firstname.c_str(),  // Convert string to C-style string
                personResult.lastname.c_str(),   // Convert string to C-style string
                personResult.age);               // Print age directly
        *GRADING << "Returned from findPerson(tp)." << endl;

        int areaResult; 

        rectangle r = {5, 10};
        
        // 
        // Call (possibly remote) area
        //
        printf("Calling area(r)\n");
        *GRADING << "Calling area(r). r.x=" << r.x << " r.y=" << r.y << endl;
        areaResult = area(r);                          
        printf("Returned from area(r). Result=%d\n", areaResult);
        *GRADING << "Returned from area(r). Result=" << areaResult << endl;

        Point pointResult;
        Point p1 = {0,1};
        Point p2 = {2,4};
        
        // Call (possibly remote) area
        printf("Calling calculateDistance(p1, p2)\n");
        *GRADING << "Calling calculateDistance(p1, p2)." << endl;
        pointResult = calculateDistance(p1, p2);                    
        printf("Returned from calculateDistance(p1, p2). Result=(%d,%d)\n", pointResult.x, pointResult.y);
        *GRADING << "Returned from calculateDistance(p1, p2)." << endl;

        // Declare an array of 10 rectangles
        rectangle rect[10];

        // Initialize the first rectangle
        rect[0] = {5, 10};

        // Optionally initialize other rectangles or leave them uninitialized
        for (int i = 1; i < 10; ++i) {
            rect[i] = {0, 0}; // Initialize remaining rectangles to default values
        }

        // Call (possibly remote) area
        printf("Calling searchRectangles(rect) \n");
        *GRADING << "Calling searchRectangles(rect)." << endl;
        searchRectangles(rect);                    
        printf("Returned from searchRectangles(rect).");
        *GRADING << "Returned from searchRectangles(rect)." << endl;

     }

     //
     //  Handle networking errors -- for now, just print message and give up!
     //
     catch (C150Exception& e) {
       // Write to debug log
       c150debug->printf(C150ALWAYSLOG,"Caught C150Exception: %s\n",
			 e.formattedExplanation().c_str());
       // In case we're logging to a file, write to the console too
       cerr << argv[0] << ": caught C150NetworkException: " << e.formattedExplanation() << endl;
     }

     return 0;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                     setUpDebugLogging
//
//        For COMP 150-IDS, a set of standards utilities
//        are provided for logging timestamped debug messages.
//        You can use them to write your own messages, but 
//        more importantly, the communication libraries provided
//        to you will write into the same logs.
//
//        As shown below, you can use the enableLogging
//        method to choose which classes of messages will show up:
//        You may want to turn on a lot for some debugging, then
//        turn off some when it gets too noisy and your core code is
//        working. You can also make up and use your own flags
//        to create different classes of debug output within your
//        application code
//
//        NEEDSWORK: should be factored into shared code w/pingstreamserver
//        NEEDSWORK: document arguments
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
void setUpDebugLogging(const char *logname, int argc, char *argv[]) {

     //   
     //           Choose where debug output should go
     //
     // The default is that debug output goes to cerr.
     //
     // Uncomment the following three lines to direct
     // debug output to a file. Comment them
     // to default to the console.
     //
     // Note: the new DebugStream and ofstream MUST live after we return
     // from setUpDebugLogging, so we have to allocate
     // them dynamically.
     //
     //
     // Explanation: 
     // 
     //     The first line is ordinary C++ to open a file
     //     as an output stream.
     //
     //     The second line wraps that will all the services
     //     of a comp 150-IDS debug stream, and names that filestreamp.
     //
     //     The third line replaces the global variable c150debug
     //     and sets it to point to the new debugstream. Since c150debug
     //     is what all the c150 debug routines use to find the debug stream,
     //     you've now effectively overridden the default.
     //
     ofstream *outstreamp = new ofstream(logname);
     DebugStream *filestreamp = new DebugStream(outstreamp);
     DebugStream::setDefaultLogger(filestreamp);

     //
     //  Put the program name and a timestamp on each line of the debug log.
     //
     c150debug->setPrefix(argv[0]);
     c150debug->enableTimestamp(); 

     //
     // Ask to receive all classes of debug message
     //
     // See c150debug.h for other classes you can enable. To get more than
     // one class, you can or (|) the flags together and pass the combined
     // mask to c150debug -> enableLogging 
     //
     // By the way, the default is to disable all output except for
     // messages written with the C150ALWAYSLOG flag. Those are typically
     // used only for things like fatal errors. So, the default is
     // for the system to run quietly without producing debug output.
     //
     c150debug->enableLogging(C150ALLDEBUG | C150RPCDEBUG | C150APPLICATION | C150NETWORKTRAFFIC | 
			      C150NETWORKDELIVERY); 
}
