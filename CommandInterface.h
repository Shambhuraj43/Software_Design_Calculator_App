//Interface for different commands that perform operations on two numbers

#include "Stack.h"
#include "CommandsFactory.h"


class CommandInterface: public CommandsFactory {

  public:

    //Constructor
    CommandInterface(Stack<int> & stack);

    //Destructor
    ~CommandInterface(void);

    //Following methods call execute method of appropriate classes
      Add * executeAdd(void);

      Subtract* executeSubtract(void);

      Multiply * executeMultiply(void);

      Divide * executeDivide(void);

      Mod * executeMod(void);

      Number* executeNumber(int num);


    Stack<int> & stack_;
    Stack <ExprNumber *> expression_;
};
