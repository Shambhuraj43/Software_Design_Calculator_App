#include "Subtract.h"

Subtract::Subtract(Stack<int> &s): BinaryExprCommand(s){}

Subtract:: ~Subtract()
{

}

//Compute method to subtract two numbers
int Subtract::compute(int num1, int num2)const{
  int result = num1 - num2;
  return result;
}
