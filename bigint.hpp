//
//  bigint.hpp
//  bigint
//
//  Created by Austin Angell on 9/16/21.
//
#include <iostream>
#ifndef bigint_hpp
#define bigint_hpp






const int CAPACITY = 200;
class bigint {
public:
    bigint();
    bigint(int num);
    bigint(const char c[]);
    void debugPrint(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream&, bigint&);
    bool operator==(const bigint& rhs);
    friend std::istream& operator>>(std::istream&, bigint&);
    bigint operator+(const bigint&) const;
    int operator[](const int&) const;
    bigint timesDigit(int) const;
    bigint times10(int) const;
    bigint operator*(const bigint&) const;
    
private:
    int arr [CAPACITY];
};
//capacity -1 so no out of bounds error


#endif /* bigint_hpp */
