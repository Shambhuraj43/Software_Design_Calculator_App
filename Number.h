#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "ExprNumber.h"
#include "Stack.h"

class Number : public ExprNumber{
  public:

    //Constructor
    Number(Stack<int> &s, int number);

    //execute method
    void execute();

    //Classs entity
    Stack <int> &s_;
    int number_;
};

#endif
