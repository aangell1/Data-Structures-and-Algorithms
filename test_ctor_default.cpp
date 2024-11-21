//  Stack class test program
//
//  Tests: copy contructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream> 
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    
{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;


        // VERIFY
        assert(x.empty());
    }
        
{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;


        // VERIFY
        assert(x.empty());
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}