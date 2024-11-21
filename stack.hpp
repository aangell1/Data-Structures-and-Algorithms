#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    Fall 2021
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
public:
	Node() : next(0) {};
	Node(const T& item) : data(item), next(0) {};
	T data;
	Node<T> *next;
};




////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
              stack     ();
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};

template <typename T>
stack<T>::stack(){
	tos = 0;
}

template <typename T>
stack<T>::~stack(){
	Node<T>  *temp;
	while(tos !=0){
		temp = tos;
		tos = tos->next;
		delete temp;
	}
}

template <typename T>
stack<T>::stack(const stack<T>& rhs) : stack<T>(){
	Node<T> *temp = rhs.tos;
	Node<T> *bot;
	while(temp !=0){
		if(tos == 0){
			tos = new Node<T>(temp->data);
			bot = tos;
		}
		else{
			bot->next = new Node<T>(temp->data);
			bot = bot->next;
		}
		temp = temp->next;
	}
}

template <typename T>
void stack<T>::swap(stack<T>& rhs){
	Node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator=(stack rhs){
	swap(rhs);
	return *this;
}

template <typename T>
void stack<T>::push(const T& item){
	assert(!full());

	Node<T> *temp = new Node<T>(item);
	temp->next = tos;
	tos = temp;
}

template <typename T>
T stack<T>::pop(){
	assert(!empty());

	T result = tos->data;
	Node <T> *temp = tos;
	tos = tos->next;
	delete temp;
	return result;
}

template <typename T>
T stack<T>::top() const {
	assert(!empty());
	return tos->data;
}

template <typename T>
bool stack<T>::full() const {
	Node<T> *temp = new(std::nothrow) Node<T>();
	if(temp == 0){
		return true;
	}
	delete temp;
	return false;
}

template <typename T>
bool stack<T>::empty() const {
	return tos == 0;
}





#endif

