////////////////////////////////////////////////////////////////////
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2021 Kent State University. All rights reserved.
//  Fall 2021
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    tree   = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree){
        src.tree->print(out);
    }
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(const std::vector<std::string>& profileName, 
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST
//
AST::~AST() {
    //NEED TO IMPLEMENT
    //Recursively traverse tree and delete from bottom up
    std::list<AST*>::const_iterator it = child.begin(); 
        while(!child.empty() && it != child.end()) 
            delete *it++;
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //NEED TO IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.tag;
    text = actual.text;
    
    for(std::list<AST*>::const_iterator it = actual.child.begin(); it != actual.child.end(); ++it){
        child.push_back(new AST(**it));
    }
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //NEED TO IMPLEMENT
    //Swap all the top level childern (pointers to AST)

    //Swap node, text, and tags
    nodes tempNode;
    tempNode = nodeType;
    nodeType = rhs.nodeType;
    rhs.nodeType = tempNode;
    
    
    std::string temp;
    temp = text;
    text = rhs.text;
    rhs.text = temp;
    
    temp = tag;
    tag = rhs.tag;
    rhs.tag = temp;
    
    temp = closeTag;
    closeTag = rhs.closeTag;
    rhs.closeTag = temp;
    
    // Use vector swap to swap child
    child.swap(rhs.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for milestone 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//  There are two types of names.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from an AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") { 
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////
//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName, 
                     const std::vector<std::string>& fileName    ) {
    //TODO: IMPLEMENT
    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"
    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"
 
    std::string profile = "#include \"profile.hpp\"";
    std::list<AST*>::iterator it = child.begin();
    while (((*it)->tag != "function") ) {
        it++; 
    }
    child.insert(it, new AST(token, profile));

    std::vector<std::string>::const_iterator vsi = profileName.begin();
    while(vsi != profileName.end()) {     
        std::string s = (*vsi);
        for(size_t i = 0; i!=s.length(); i++){
            if(s[i] == '_'){
                s[i] = '.';
            }
        }
        profile = "\nprofile " + (*vsi) + "(\"" + s + "\")" + ";\n"; 
        child.insert(it, new AST(token, profile));
        ++vsi;  
    }
}
    


/////////////////////////////////////////////////////////////////////
//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {

    //TODO: IMPLEMENT
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"
    
    std::list<AST*>::iterator it = child.begin();
    while (((*it)->tag != "function") ) {
        it++;
    }
    std::string s = profileName;
    size_t i = 0; 
    for(size_t i = 0; i!=s.length(); i++){
            if(s[i] == '_'){
                s[i] = '.';
            }
        }
    std::string profile = "#include \"profile.hpp\"";
    profile = profile + "\nextern profile " + profileName + ";\n\n"; 
    child.insert(it, new AST(token, profile));
}



/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //TODO: IMPLEMENT
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return
  
    std::list<AST*>::iterator it = child.begin();
    while(it != child.end()) {
        if(((*it)->tag == "function") && ((*it)->getName() == "main")) {
        AST *ptr = (*it)->getChild("block");
        std::list<AST*>::iterator bit = ptr->child.begin();
        while((*bit)->tag != "return") {
            ++bit;
        }
        --bit;
        AST *output = new AST(token);
        std::string os;
        for(std::vector<std::string>::const_iterator vsi = profileName.begin(); vsi !=profileName.end(); ++vsi) {
            os = os + ("std::cout<< " + (*vsi) + " <<std::endl; \n");
        }
        output->text = os;
        ptr->child.insert(bit,output);
    }
    ++it; 
  }

}

/////////////////////////////////////////////////////////////////////
// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {

    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");

  std::list<AST*>::iterator it = child.begin();
  while(it!=child.end()) {
    if( ((*it)->tag == "function") || ((*it)->tag == "constructor") ||  ((*it)->tag == "destructor"))  {
      AST *ptr = (*it)->getChild("block");
      std::string function,count;
      AST *name = (*it)->getChild("name");
      AST *nameChild = name->child.front();
      function = nameChild->text;
      count = " " + profileName +".count(__LINE__, \"" + function + "\"); \n";
      AST *p = new AST(token);
      p -> text = count;
      
      std::list<AST*>::iterator bit = ptr->child.begin();
      while((*bit)->text != "{") {
        ++bit;
      }
      ++bit;
      ptr->child.insert(bit,p);
    }
    ++it;
  }
}


/////////////////////////////////////////////////////////////////////
// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing
    
    std::string count = (" " + profileName +".count(__LINE__); \n");
    std::list<AST*>::iterator it = child.begin();

    while(it != child.end()) {
        if(! (*it)->child.empty()) {
            (*it)->lineCount(profileName);
        }

        if((*it)->tag == "expr_stmt") {
            AST *p = new AST(token);
            p->text = count;
            (*it) -> child.push_back(p);
        }
        ++it;
  }
}  

/////////////////////////////////////////////////////////////////////
// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"            ) return true; //Remove for challenge
    if (tag == "type"                 ) return true;
    if (tag == "name"                 ) return true;
    if (tag == "return"               ) return true;
    if (tag == "break"                ) return true;
    if (tag == "continue"             ) return true;
    if (tag == "parameter_list"       ) return true;
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}

/////////////////////////////////////////////////////////////////////
// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//

std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}
    



/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.

std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

