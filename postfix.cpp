////////////////////////////////////////////////////////////////////////////
//
// File: postfix.cpp
//
// Programmer: Austin Angell
// Updated:    Fall 2021
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <fstream>
#include <iostream>
#include "utilities.hpp"
#include "stack.hpp"
int main(int argc, char const* argv[])
{
    if (argc < 2) {
       std::cerr << "No file has been inputted" << std::endl;
}
    std::ifstream infix(argv[1]);
     if (!infix) {
       std::cerr << "Couldnt open infix file" << std::endl;
}
   std::ofstream postfix(argv[2]);
   if (!postfix) {
       convertToPostfix(infix, std::cout);
}
   convertToPostfix(infix, postfix);
   infix.close();
   postfix.close();
   
   
   return 0; 

}