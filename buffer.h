#ifndef BUFFER_H
#define BUFFER_H

#include <cstdlib> 
#include <cstring> 
#include <string>    
#include <iostream>  

// Define the Buffer struct
struct Buffer {
    char *buf;      // Pointer to the buffer
    int length;    // Length of the buffer

    // Constructor 
    Buffer() : buf(nullptr), length(0) {}

    // Copy Constructor
    Buffer(const Buffer &other) {
        // Allocate memory for the new buffer and copy the data from the 'other' buffer
        length = other.length;
        buf = (char *)malloc(length);  

        if (buf) {  
            // Copy the data from the original buffer
            memcpy(buf, other.buf, length);
        } 
        else {
            // Handle allocation failure, e.g., throw an exception or handle error
            length = 0;
        }
    }

    // Destructor 
    ~Buffer() {
        if (buf) {
			// Free the buffer if it is allocated
            free(buf);
        }
    }

    // Reset the buffer
    void reset() {
        if (buf) {
            free(buf);
            buf = nullptr;
            length = 0;
        }
    }

    void reset(char *newBuf, int newLength) {
        if (buf) {
            free(buf);
            buf = newBuf;
            length = newLength;
        }
    }
};

#endif  // BUFFER_H
