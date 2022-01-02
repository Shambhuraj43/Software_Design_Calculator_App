#ifndef _UNARYEXPRCOMMAND_H_
#define _UNARYEXPRCOMMAND_H_

#include "Stack.h"
#include "ExprNumber.h"


class UnaryExprCommand : public ExprNumber
{

public:

  //Contrsuctor
  UnaryExprCommand(Stack <int> & s);

  //Destructor
  ~UnaryExprCommand();

  //Execute methods
  void execute (void);

  //Virtual method to be defined by the derived class
  virtual int compute (int num1) const = 0;

//Class entity
  Stack <int> & s_;

};

#endif
