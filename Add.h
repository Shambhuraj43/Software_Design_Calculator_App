#ifndef _ADD_H_
#define _ADD_H_


#include "Stack.h"
#include "BinaryExprCommand.h"


//Add Class  
class Add: public BinaryExprCommand{
  public:

    //Consructor
    Add(Stack<int> &s);

    //Destructor
     ~Add();

    //Compute method to add two numbers
    int compute(int num1, int num2) const;
};

#endif
