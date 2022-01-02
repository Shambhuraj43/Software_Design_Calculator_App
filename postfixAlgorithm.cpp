#include "postfixAlgorithm.h"
#include "ExprNumber.h"
#include "Array.h"
#include "Stack.h"
#include "ExprStackIt.h"

// Convert to postfix from infix
bool postfixAlgorithm(const std::string &expression,
                  ExprStackIt &factory,
                  Stack<ExprNumber *> &postfix)
{

    std::istringstream input(expression);

    std::string parse;
    int ctr1 = 0;
    int ctr2 = 0;
    Add* add=nullptr;
    Subtract* sub=nullptr;
    Multiply* mul=nullptr;
    Divide* div=nullptr;
    Number* integer=nullptr;
    Stack<ExprNumber *> temp;

    //Execute the loop until user inputs QUIT
    while (!input.eof())
    {
        input >> parse;

        //Determine the operation to be performed and call the apprpriate commands
        if (!parse.compare("+"))
        {
            add = factory.executeAdd();
            postfix.push(add);
        }
        else if (!parse.compare("-"))
        {
            sub = factory.executeSubtract();
            postfix.push(sub);
        }
        else if (!parse.compare("*"))
        {
            mul = factory.executeMultiply();
            postfix.push(mul);
        }
        else if (!parse.compare("/"))
        {
            div = factory.executeDivide();
            postfix.push(div);
        }
        else if (!parse.compare("("))
        {
           ++ctr1;
        }
        else if (!parse.compare(")"))
        {
            ++ctr2;
        }
        else if (numCheck(parse))
        {
            std::istringstream temp_num(parse);
            int temp = 0;
            temp_num >> temp;
            number = factory.executeNumber(temp);
            postfix.push(number);
        }
        else
        {
            //do noting
        }

        if(ctr1 != ctr2){

        }
    }
    return true;
}
