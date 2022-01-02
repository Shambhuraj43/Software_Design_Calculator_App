#ifndef _MOD_H_
#define _MOD_H_

#include "BinaryExprCommand.h"

//Mod class definition for Modulo command
class Mod: public BinaryExprCommand
{
public:
  //Constructor
  Mod(Stack <int> & s);

  //Destructor
  ~Mod();

  //Compute method to calculate the answer
  int compute (int num1, int num2) const;
};

#endif
