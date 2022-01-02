#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <cstring>
#include "Stack.h"

template <typename T>
  class Iterator{
    public:
      typedef T type_of_data;

      //Contructor
      Iterator(Stack <T> &s);

      //Destructor
      ~Iterator(void);

      //isDone method
      bool isDone(void);

      //operator *
      T operator *(void);

      //operator ->
      T * operator -> (void);

      //advance method
      void advance(void);

    //private entities
    Stack <T> & s_;

    size_t current_;
  };

#include "Iterator.cpp"
#endif
