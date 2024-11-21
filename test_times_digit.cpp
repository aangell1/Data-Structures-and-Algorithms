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
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(4);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 8);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 81);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 1);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 20);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 4);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(7);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 21);  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}

