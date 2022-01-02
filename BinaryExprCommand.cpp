#include "BinaryExprCommand.h"
#include "Stack.h"

//Contrsuctor
BinaryExprCommand::BinaryExprCommand (Stack<int> &s):s_ (s){}

//Destructor
BinaryExprCommand::~BinaryExprCommand (void){}

//execute method
void BinaryExprCommand::execute(void){

  //Get the top element and remove it from stack
  //Store it in a temp variable to access later
    int num2 = s_.top();
    s_.pop();

    //Get the top element and remove it from stack
    //Store it in a temp variable to access later
    int num1 = s_.top();
    s_.pop();

    //Perform the operation
    int result = this->compute(num1,num2);
    s_.push(result);
}
