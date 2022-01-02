#include "Calculate.h"

//Contructor
Calculate:: Calculate(void) :factory(CommandInterface(resultStack))
{

}

//Destructor
Calculate:: ~Calculate(void)
{

}

//This function will get the input from console, parse it, and convert the expression
//to postfix from infix
void Calculate:: calculateExpression(void)
{
  bool control = true;
  std::string input;

  //Get the input unless the user inputs QUIT
  while(control)
  {
    std::cout << "Enter valid input ";
    std::getline(std::cin, input);

    if(input == "QUIT")
      control = false;
    else
    {
      Array <ExprNumber *> commands;
      try
      {
	postfixAlgorithm(input, commands);               //Call function which converst the expression to postfix from infix

  for(int i = 0; i < commands.size(); i++)
	{
	  commands[i]->execute();
	}
	 std:: cout << resultStack.top() << std::endl;
	  resultStack.pop();
      }
      catch(std::exception& Ex)
      {
	std::cout << Ex.what() << std::endl;
      }
    }
  }
}

//Function to convert the infix expression to postfix expression
bool Calculate:: postfixAlgorithm(const std::string & infixInput, Array <ExprNumber *> & postfix)
{
  //Convert the string
  std::istringstream input(infixInput);
  std::string token;

  ExprNumber * expression = 0;
  Stack <ExprNumber *> temp;


  Stack <int> precedence, parenthesis;
  parenthesis.push(-1);
  int ctr;

  while(!input.eof())
  {
    input >> token;


    if(token == "(")
      parenthesis.push(temp.size());
    else if(token == ")")
    {

      while(temp.size() > parenthesis.top())
      {
	postfix.resize(postfix.size()+1);
	postfix[postfix.size() - 1] = temp.top();
	temp.pop();
	precedence.pop();
      }
      parenthesis.pop();
    }


    //Check the token to decide the operation
    else if(token.length() == 1 && !isdigit(token[0]))
    {
      if(token == "+")
      {
	expression = factory.executeAdd();
	ctr = 0;
      }
      else if(token == "-")
      {
	expression = factory.executeSubtract();
	ctr = 0;
      }
      else if(token == "*")
      {
	expression = factory.executeMultiply();
	ctr = 1;
      }
      else if(token == "/")
      {
	expression = factory.executeDivide();
	ctr = 1;
      }
      else if(token == "%")
      {
	expression = factory.executeMod();
	ctr = 1;
      }
      else
      {
	throw std::invalid_argument("Invalid Input");
      }

      //pop from temp stack until top operation has lower precedenceedence
      //or until an opening parenthesisthesis is found
      while(!precedence.is_empty() && precedence.top() >= ctr && temp.size() != parenthesis.top())
      {
	postfix.resize(postfix.size()+1);
	postfix[postfix.size() - 1] = temp.top();
	temp.pop();
	precedence.pop();
      }
      //Check the token and push accordingly
      temp.push(expression);
      precedence.push(ctr);
    }

    else
    {
      bool isValid = true;
      for(int i = 0; i < token.length(); i++)
      {
	if(i == 0)
	{
	  if(!isdigit(token[i]) && token[i] != '-')
	    isValid = false;
	}
	else if(!isdigit(token[i])){
	  isValid = false;
	}
      }
      if(!isValid)
	throw std::invalid_argument("Invalid Input");

      expression = factory.executeNumber(std::stoi(token));
      postfix.resize(postfix.size()+1);
      postfix[postfix.size() - 1] = expression;
    }
  }

  //Check for Invalid Input
  if(parenthesis.size() > 1)
  {
    throw std::invalid_argument("Invalid Input");
  }

  while(!temp.is_empty())
  {
    postfix.resize(postfix.size()+1);
    postfix[postfix.size() - 1] = temp.top();
    temp.pop();
  }

  return true;
}
