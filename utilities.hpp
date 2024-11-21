#ifndef CS2_STACK_UTIL
#define CS2_STACK_UTIL

////////////////////////////////////////////////////////////////////////////
//
// File: utilities.hpp
//
// Programmer: Austin Angell
// Updated:    Fall 2021
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//


#include<iostream>
#include <fstream>
#include "../string/string.hpp"
#include "stack.hpp"


void convertToPostfix(std::ifstream&, std::ostream&);

void convertToAssembly(std::ifstream& in, std::ostream&
out);
std::string convertInt(int);
std::string getop(const std::string& op);
std::string getT(std::ifstream& in);




#endif