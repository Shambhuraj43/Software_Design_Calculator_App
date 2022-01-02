#include "ExprStackIt.h"

//Mthod to check the recieved string from user 
bool numCheck(std::string number);

// Comvert to postfix from infix
bool postfixAlgorithm(const std::string &expression,
                  ExprStackIt &factory,
                  Stack<ExprNumber *> &postfix);
