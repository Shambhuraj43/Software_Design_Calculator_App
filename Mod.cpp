//Mod class for Modulo command
#include "Mod.h"

//Constructor
Mod:: Mod(Stack <int> & s)
  :BinaryExprCommand(s)
{

}

//Destructor
Mod:: ~Mod()
{

}

//COmpute method to perform the operation
int Mod:: compute(int num1, int num2) const
{
  return num1 % num2;
}
