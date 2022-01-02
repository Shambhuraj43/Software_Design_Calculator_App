#ifndef _BINARYEXPRCOMMAND_H_
#define _BINARYEXPRCOMMAND_H_

#include "ExprNumber.h"
#include "Stack.h"

class BinaryExprCommand : public ExprNumber {

  public:

    //Constructor
    BinaryExprCommand(Stack<int> &s);

    //Destructor
    ~BinaryExprCommand();

    //execute method
    void execute(void);

    //compute method will be defines in derived classes
    virtual int compute(int num1, int num2)const=0;


    //Class entity
    Stack <int> & s_;
};
#endif
