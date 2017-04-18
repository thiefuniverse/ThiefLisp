//
// Created by thief on 17-4-15.
//

#include "ThiefLisp_Expr.h"

using namespace ThiefLispSpace;

ThiefLisp_Expr::~ThiefLisp_Expr()
{
  
}

void TL_Expr_Number::parsedCompleted()
{
  std::cout<<"parsed a number\n";
}

void TL_Expr_Func_Proto::parsedCompleted()
{
    std::cout<<"parsed a Func prototype\n";
}
void TL_Expr_Function::parsedCompleted()
{
    std::cout<<"parsed a function\n";
}
void TL_Variable::parsedCompleted()
{
    std::cout<<"parsed a variable\n";
}
void TL_Expr_List::parsedCompleted()
{
    std::cout<<"parsed a list\n";
}