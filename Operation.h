#include "ExprNumber.h"
#include "BinaryExprCommand.h"
#include "Number.h"

class Operation{

  //Constructor
  Operation();

  //Destructor
  virtual ~Operation() = 0;

/************************************************************************/
//Methods for differnt operations to be performed after parsing the input
  virtual void OperationAdd() = 0;

  virtual void OperationSubtract() = 0;

  virtual void OperationMultiply() = 0;

  virtual void OperationDivide() = 0;

  virtual void OperationNumber() = 0;
  /************************************************************************/

  //For open and close parantheses
  virtual void OperationOpenPara() = 0;
  virtual void OperationClosePara() = 0;

  int result();
  int NumberResult;
};
