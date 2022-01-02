// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//#include "Array.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
  :arr_ (Array <T> (stack.arr_))
{
 
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  arr_.resize(size()+1);
  arr_.set(size()-1,element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
  if(is_empty())
  {
    throw empty_exception();
  }
  arr_.resize(size()-1);
}

// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  // COMMENT Check for self-assignment
  // RESPONSE Added line to check for self-assignment before
  // assigning data. Also changed method to call the Array =
  // operator to reduce redundant code
  if (this != &rhs)
    this->arr_ = rhs.arr_;

  return *this;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{ 
  arr_.resize(0);
}
