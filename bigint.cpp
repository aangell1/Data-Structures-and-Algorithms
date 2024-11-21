//
//  bigint.cpp
//  bigint
//
//  Created by Austin Angell on 9/16/21.
//

#include "bigint.hpp"

#include <iostream>


bigint::bigint(){
    for(int i=0; i < CAPACITY; i++){
        arr[i]=0;
    }
}
bigint::bigint(int num): bigint(){
    for(int i=0; num!= 0; i++ ){
        arr[i] = num % 10;
        num/=10;
    }
}
bigint::bigint(const char c[]) : bigint(){
    int i=0;
    int newArr[CAPACITY];
    while(c[i] != 0){
        newArr[i] = c[i] - '0';
        i++;
    }
    i--;
    int a=0;
    while (i>=0){
        arr[a] = newArr[i];
        i--;
        a++;
    }
    
}
void bigint::debugPrint(std::ostream& out) const {
    for(int i =0; i < CAPACITY-1; i++){
        out << arr[i] << "|";
    }
}

std::ostream& operator<<(std::ostream& o, bigint& b){
    int i;
    for(i = CAPACITY-1; b.arr[i]==0; i--){
    }
    for(;i >= 0; i--){
        o << b.arr[i];
    }
    return o;
}

bool bigint::operator==(const bigint& rhs){
    for(int i=0; i<CAPACITY; i++){
        if(arr[i] != rhs.arr[i]){
            return false;
        }
    }
    return true;
}

std::istream& operator>>(std::istream& in, bigint& b){
    char c[CAPACITY];
    int i= 0;
    while(!in.eof()){
        in >> c[i];
        if(c[i] == ';'){
            break;
        }
        ++i;
    }
    c[i] = 0;
    b = bigint(c);
    return in;
}
bigint bigint::operator+(const bigint& rhs) const{
    bigint result;
    int r;
    int carry = 0;
    for(int i = 0; i < CAPACITY; i++){
        r = rhs.arr[i] + arr[i];
        carry = r/10;
        r = r % 10;
        result.arr[i] += r;
        if(i != CAPACITY-1){
            result.arr[i+1] +=carry;
        }
    }
    return result;
}
int bigint::operator[](const int& a) const{
    return arr[a];
}
bigint bigint::timesDigit(int a) const{
    bigint resultOfMultpily;
    for(int i = 0; i < a; i++){
        resultOfMultpily = operator+(resultOfMultpily);
    }
    return resultOfMultpily;
}
bigint bigint::times10(int b) const{
    bigint r;
    for( int i = CAPACITY -1 - b; i >=0; i--){
        r.arr[i + b] = arr[i];
    }
    return r;
}

bigint bigint::operator*(const bigint& rhs) const {
    bigint temp;
    bigint product = 0;
    for(int i = 0; i < CAPACITY-1; i++){
        temp = rhs.timesDigit(arr[i]);
        product = product + temp.times10(i);
    }
    return product;
}
