// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    {
     // Setup
        bigint bi(9);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 9);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 9);
}
{
         // Setup
        bigint bi(1);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 1);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 0);
}
{
         // Setup
        bigint bi(5);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 5);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 5);
}


    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

