#include<string>
#include<iostream>
#include<sstream>
#include<cctype>
#include<stdexcept>
#include <exception>
#include "CommandInterface.h"
//#include "CommandsFactory.h"


class Calculate
{
  public:

    //Contrscutor
    Calculate(void);

    //Destructor
     ~Calculate(void);

    //Calculate method
    void calculateExpression(void);

    //convert to postfix from infix 
    bool postfixAlgorithm(const std:: string & inputInfix,Array <ExprNumber *> &postfix);

    //Class entities
    Stack <int> resultStack;
    CommandInterface factory;

};
