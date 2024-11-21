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
        x.push(30);




        // VERIFY

        assert(x.top() == 30);
        assert(x.pop() == 30);
        assert(x.top() == 5);
        assert(x.pop() == 5);

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;
        x.push("abcdefg");
        x.push("xyz");
        x.push("12345");
        x.pop();
        x.pop();
        x.push("xyz");




        // VERIFY

        assert(x.top() == "xyz");
        assert(x.pop() == "xyz");
        assert(x.top() == "abcdefg");
        assert(x.pop() == "abcdefg");

    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<double>  x;
        x.push(5.12);
        x.push(30.87);
        x.push(80.56);
        x.pop();
        x.pop();
        x.push(30.87);




        // VERIFY

        assert(x.top() == 30.87);
        assert(x.pop() == 30.87);
        assert(x.top() == 5.12);
        assert(x.pop() == 5.12);

    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing push pop." << std::endl;
    return 0;
}