#ifndef _DIVIDE_H_
#define _DIVIDE_H_


#include "BinaryExprCommand.h"


class Divide: public BinaryExprCommand{
  public:

    //Contsructor
    Divide(Stack<int> &s);

    //Destructor
   ~Divide();

    //Compute method to divide two numbers
    int compute(int num1, int num2) const;
};
#endif
