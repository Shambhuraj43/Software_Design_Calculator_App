#include "Add.h"


//Constructor for Add class
Add::Add(Stack<int> &s):BinaryExprCommand(s)
{

}

//Destructor for Add class
Add::~Add()
{

}

//Compute method to add two numbers
int Add::compute(int num1, int num2) const{
  int result = num1 + num2;
  return result;
}
