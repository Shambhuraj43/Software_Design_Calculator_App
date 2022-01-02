#include "Divide.h"

Divide::Divide(Stack<int> &s): BinaryExprCommand(s){}

Divide::  ~Divide(){

}

//Compute method to divide two numbers
int Divide::compute(int num1, int num2) const{
  // COMMENT: Your code will crash if you have divide by 0.
  // Throwing execption if divided by zero 
  if(num2 == 0){
    throw std::invalid_argument("Cannot divide by zero");
  }

  int result = num1 / num2;
  return result;
}
