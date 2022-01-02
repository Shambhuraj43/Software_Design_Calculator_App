//Interface class for differnt commands

#include "CommandInterface.h"


//Contructor
CommandInterface::CommandInterface(Stack<int> & stack): stack_(stack)
{

}

//Destructor
CommandInterface::~CommandInterface(void)
{
  //Delete every element in the expression stack
  while(!expression_.is_empty())
  {
    delete expression_.top();
    expression_.pop();
  }
}

//Execute Add command
Add * CommandInterface::executeAdd(void)
{
  Add* expression = new Add(stack_);
  expression_.push(expression);
  return expression;
}

//Execute Subtract command
Subtract * CommandInterface::executeSubtract(void)
{
    Subtract * expression = new Subtract(stack_);
    expression_.push(expression);
    return expression;
}

//Execute Multiply command
Multiply * CommandInterface:: executeMultiply(void)
{
  Multiply * expression = new Multiply(stack_);
  expression_.push(expression);
  return expression;
}


Divide * CommandInterface:: executeDivide(void)
{
  Divide * expression = new Divide(stack_);
  expression_.push(expression);
  return expression;
}

Mod * CommandInterface:: executeMod(void)
{
  Mod * expression = new Mod(stack_);
  expression_.push(expression);
  return expression;
}

Number* CommandInterface:: executeNumber(int num)
{
  Number * expression = new Number(stack_,num);
  expression_.push(expression);
  return expression;
}
