#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "Stack.h"
#include "BinaryExprCommand.h"


class Multiply: public BinaryExprCommand{
  public:

    //Constructor
    Multiply(Stack<int> &s);

    //Destructor
     ~Multiply();

    //Compute method to multiply two numbers
    int compute(int num1, int num2) const;
};

#endif
