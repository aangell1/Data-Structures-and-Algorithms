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
        x.push(5);
        x.push(30);
        x.push(80);
        x.pop();
        x.pop();




        // VERIFY
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        x.push("abcdef");
        x.push("xyz");
        x.push("123");
        x.pop();
        x.pop();




        // VERIFY
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing destructor." << std::endl;
    return 0;
}