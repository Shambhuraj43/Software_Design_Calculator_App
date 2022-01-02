#ifndef _SUBTRACT_H_
#define _SUBTRACT_H_

#include "Stack.h"
#include "BinaryExprCommand.h"


class Subtract: public BinaryExprCommand{
  public:
    Subtract(Stack<int> &s);
    virtual ~Subtract();
    int compute(int num1, int num2)const;
};
#endif
