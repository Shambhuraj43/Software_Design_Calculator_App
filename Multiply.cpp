#include "Multiply.h"

//Constructor
Multiply::Multiply(Stack<int> &s):BinaryExprCommand(s){}

Multiply:: ~Multiply(){

}

//Compute method to Multiply two numbers
int Multiply::compute(int num1, int num2) const {
  int result = num1 * num2;
  return result;
}
