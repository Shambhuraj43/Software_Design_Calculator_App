#ifndef _UNARYEXPRCOMMAND_H_
#define _UNARYEXPRCOMMAND_H_

#include "UnaryExprCommand.h"

UnaryExprCommand:: UnaryExprCommand(Stack <int> & s)
  :s_ (s)
{

}

UnaryExprCommand:: ~UnaryExprCommand(void)
{

}

//remove top value from stack and perform unary operation and push result
void UnaryExprCommand:: execute(void)
{
  int num = this->s_.top();
  this->s_.pop();

  int result = this->compute(num);

  this->s_.push(result);

}

#endif
