//Header File Definition – override C++ vector definition

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector
{
public:
    Vector();          		// default constructor
    Vector(int);   		// makes size = s, 
                                   //allocates s space
               //   e.g. entries = new int[size], 
                                   // makes all entries 0
    Vector(const Vector &other);
    // copy constructor
    // makes a deep copy
    ~Vector();      		// default destructor
    void print();    		// Prints out the vector

    void set(int val, int pos); 	// if 0 <=pos<size
                                   //    stores val at pos in entries
               // otherwise
               //    error message 
    Vector& operator=(const Vector& other); //overload = operator for the same reason we write a copy constructor due to the pointer data member of the class
private:
    int size;          			 // sets the # of elements used  
    int* entries;			// point to array of integers with size entries
                           //   e.g. entries = new int[size]
};

#endif 
