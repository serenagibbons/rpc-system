// --------------------------------------------------------------
//
//                        testarray1client.cpp
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
//              testarray1client <servername> 
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
#include "testarray1.idl"

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

     //  Set up debug message logging
     setUpDebugLogging("testarray1clientdebug.txt",argc, argv);

     // Make sure command line looks right
     if (argc != 2) {
       fprintf(stderr,"Correct syntxt is: %s <servername> \n", argv[0]);
       exit(1);
     }

     //  DO THIS FIRST OR YOUR ASSIGNMENT WON'T BE GRADED!
     GRADEME(argc, argv);

     // Call the functions and see if they return
     try {

        // Set up the socket so the proxies can find it
        rpcproxyinitialize(argv[serverArg]);

        int x[24] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
        int y[24] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
        
        printf("Calling sqrt(x, y)\n");
        int intResult = sqrt(x, y);                  
        printf("Returned from sqrt(x, y). Result: %d\n", intResult); // Print result

        float z[10] = {1,2,3,4,5,6,7,8,9,10};

        printf("Calling add(z)\n");
        float floatResult = add(z);                  
        printf("Returned from add(z). Result: %f\n", floatResult); // Print result
     }

     // Handle networking errors -- for now, just print message and give up!
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
