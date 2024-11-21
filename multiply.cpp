//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-2.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-2.txt, exiting." << std::endl;
        exit(1);
    }
     bigint a, b, result;
    while(!in.eof()){
        in >> a;
        if(in.eof()){
            break;
        }
        in >> b;
        std::cout << "First bigint: " << a << std::endl;
        std::cout << "Second bigint: " << b << std::endl;
        result = a + b;
        std::cout << "Result of the two bigints added together: " << result << std::endl;
    }
    in.close();
    return 0;
}

