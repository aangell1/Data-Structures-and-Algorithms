////////////////////////////////////////////////////////////////////////////
//
// File: utilities.cpp
//
// Programmer: Austin Angell
// Updated:    Fall 2021
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//



#include "utilities.hpp"
#include "stack.hpp"
#include "../string/string.hpp"



void convertToPostfix(std::ifstream& in, std::ostream& out) {
   stack<String> s;
   String op, ct, l, r;
   char t[300];
   while (!in.eof()) {
        in >> t;
        ct = String(t);
        if (in.eof()) {
           break;
        }
        if (ct == ";") {
           out << s.top();
           out << ";";
           out << std::endl;
           s = stack<String>();
        } 
        else if (ct == ")") {
           r = s.pop();
           op = s.pop();
           l = s.pop();
           s.push(l + r + op);
        } 
        else {
            if (ct != "(") {
               s.push(ct + ' ');
            }
        }
 
    }
}   
    void convertToAssembly(std::ifstream& in, std::ostream& out) {
    stack<std::string> s;
    std::string lhs;
    std::string rhs;
    std::string op;
    std::string temp;
    std::string ct;
    int t = 1;
    while (!in.eof()) {
        ct = getT(in);
        if (ct == ";") {
           temp = "TMP" + convertInt(t++);
           out << "   ST    " << temp << std::endl;
           out << "=============================================" << std::endl;
           temp = 1; 
        }
        if (!in.eof() && ct != "+" && ct != "-" && ct != "*" && ct != "/") {
           s.push(ct);
        } 
        else if (!in.eof()) {
           rhs = s.pop();
           lhs = s.pop();
           out << "   LD    " << lhs << std::endl;
           op = getop(ct);
           out << op << rhs << std::endl;
           temp = "TMP" + convertInt(t++);
           s.push(temp);
           out << "   ST    " << temp << std::endl;
       }
    }
}
std::string getop(const std::string& op){
    switch(op[0]){
        case '+':
            return "   AD\t ";
            break;
        case '-':
            return "   SB\t ";
            break;
        case '*':
            return "    MU\t ";
            break;
        case '/':
            return "    DV\t";
            break;
        default:
            return "    UNDEF\t";
    }
}
std::string convertInt(int x) {
   if (!x) {
    return "0"; 
    }
   std::string r;
   do {
       r += (x % 10);
       x = x/10;
   } 
   while (x > 0);
   return r;
}
std::string getT(std::ifstream& in) {
   std::string r;
   char t = '\0';
   for (int i = 0; t != ' ' && !in.eof(); ++i) {
        in.get(t);
        if (t == ';') {
           return ";";
        } 
        else if (t != ' ') {
           r += t;
        } 
    }
   return r;
}