#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Mod.h"
#include "Number.h"

class CommandsFactory
{
  public:

    //Destructor
    virtual ~CommandsFactory(void) = 0;

    //These methods call execute method of the appropriate classes
    //All are virtual methods and will be definned in teh derived class

    // call appropriate method of the class to compute
    virtual Add * executeAdd(void) = 0;

    // call appropriate method of the class to compute
    virtual Subtract* executeSubtract(void) = 0;

    // call appropriate method of the class to compute
    virtual Multiply* executeMultiply(void) = 0;

// call appropriate method of the class to compute
    virtual Divide * executeDivide(void) = 0;

// call appropriate method of the class to compute
    virtual Mod * executeMod(void) = 0;

// call appropriate method of the class to compute
    virtual Number* executeNumber(int num) = 0;


};
