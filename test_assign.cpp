//  Stack class test program
//
//  Tests: XXX
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
        stack<int> y=x;


        // VERIFY
        assert(y.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;
        x.push(5);
        x.push(30);
        stack<int> y=x;
        assert(y.pop()== 30);
        assert(y.pop() == 5);




        // VERIFY
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        stack<String> y=x;


        // VERIFY
        assert(y.empty());
    }

      {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        x.push("abc");
        x.push("def");
        stack<String> y=x;
        assert(y.pop()== "def");
        assert(y.pop() == "abc");




        // VERIFY
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing assign." << std::endl;
    return 0;
}

