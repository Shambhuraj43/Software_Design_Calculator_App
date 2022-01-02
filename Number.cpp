#include "Number.h"

//Constructor initialization
Number::Number(Stack<int> &s, int number): s_(s), number_(number){

}

//execute method
void Number::execute(){

//push on to stack
  s_.push(this->number_);

};
