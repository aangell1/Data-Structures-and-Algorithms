// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        std::cout << bi << std::endl;
        assert(bi == 3);  //Wrong. Will FAIL, fix and add tests cases
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5);

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == 500000);  //Wrong. Will FAIL, fix and add tests cases
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 300);  //Wrong. Will FAIL, fix and add tests cases
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(2);

        // Test 
        bi = bi.times10(4);

        // Verify
        assert(bi == 20000);  //Wrong. Will FAIL, fix and add tests cases
    }

    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

