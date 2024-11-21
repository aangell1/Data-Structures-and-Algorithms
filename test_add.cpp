// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

     //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 9);
      assert(result == 18);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(19);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 19);
      assert(result == 28);
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(29);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 29);
      assert(result == 38);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(19);
      bigint right(18);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 19);
      assert(right  == 18);
      assert(result == 37);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(48);
      bigint right(48);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 48);
      assert(right  == 48);
      assert(result == 96);
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(100);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 100);
      assert(right  == 1);
      assert(result == 101);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(100);
      bigint right(10);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 100);
      assert(right  == 10);
      assert(result == 110);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("109");
      bigint right("9");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "109");
      assert(right  == "9");
      assert(result == "118");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("100");
      bigint right("101");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "100");
      assert(right  == "101");
      assert(result == "201");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("80");
      bigint right("29");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "80");
      assert(right  == "29");
      assert(result == "109");
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000");
      bigint right("101");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "1000");
      assert(right  == "101");
      assert(result == "1101");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("600");
      bigint right("401");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "600");
      assert(right  == "401");
      assert(result == "1001");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000");
      bigint right("4000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "1000");
      assert(right  == "4000");
      assert(result == "5000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("6000");
      bigint right("5000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "6000");
      assert(right  == "5000");
      assert(result == "11000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("11000");
      bigint right("8000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "11000");
      assert(right  == "8000");
      assert(result == "19000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("19000");
      bigint right("2000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "19000");
      assert(right  == "2000");
      assert(result == "21000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("21000");
      bigint right("80000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "21000");
      assert(right  == "80000");
      assert(result == "101000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1001000");
      bigint right("9000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==   "1001000");
      assert(right  ==  "9000000");
      assert(result == "10001000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("10001000");
      bigint right("90000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==   "10001000");
      assert(right  ==   "90000000");
      assert(result ==  "100001000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000");
      bigint right("9000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==    "1000000000");
      assert(right  ==    "9000000000");
      assert(result ==   "10000000000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000000");
      bigint right("9000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==    "1000000000000");
      assert(right  ==    "9000000000000");
      assert(result ==   "10000000000000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000000000");
      bigint right("9000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==    "1000000000000000");
      assert(right  ==    "9000000000000000");
      assert(result ==   "10000000000000000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000000000000");
      bigint right("9000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==    "1000000000000000000");
      assert(right  ==    "9000000000000000000");
      assert(result ==   "10000000000000000000");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000000000000000");
      bigint right("9000000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==    "1000000000000000000000");
      assert(right  ==    "9000000000000000000000");
      assert(result ==   "10000000000000000000000");
    }
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

