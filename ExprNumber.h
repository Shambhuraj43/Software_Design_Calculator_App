#ifndef _EXPRNUMBER_H_
#define _EXPRNUMBER_H_


//#include "Stack.h"


class ExprNumber{
  public :


      //Constructor
        virtual ~ExprNumber(void) = 0;

        //execute method for this class will be defined by the derived class
        virtual void execute(void) = 0;


};
#endif
