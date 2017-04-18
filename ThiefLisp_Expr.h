//
// Created by thief on 17-4-15.
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#ifndef READ_LINE_TEST_THIEFLISP_EXPR_H
#define READ_LINE_TEST_THIEFLISP_EXPR_H

using TL_Number = int;

namespace  ThiefLispSpace {

enum ExprType{
    TL_FUNCTION=1,
    TL_NUMBER=2,
    TL_LIST=3,
    TL_VARIABLE=4
};


    // expression system for ThiefLisp
    class ThiefLisp_Expr {
    public:
            virtual void parsedCompleted()=0;
            virtual ~ThiefLisp_Expr();
    private:

    };


    class TL_Expr_Number: public ThiefLisp_Expr{
    public:
        TL_Expr_Number(TL_Number num)
        :_number(num)
        {
            
        }
        void parsedCompleted();
    private:
        TL_Number _number;
    };

// keep function prototype arguments
    class TL_Expr_Func_Proto:public ThiefLisp_Expr{
    public:
        void parsedCompleted();
    private:
        std::vector<ExprType> Args;
    };
    
    class TL_Expr_Function:public ThiefLisp_Expr{
    public:
            void parsedCompleted();
    private:
            
        TL_Expr_Func_Proto _proto;
    };

    class TL_Expr_List:public ThiefLisp_Expr{
        public:
        void parsedCompleted();
    };
    
    class TL_Variable:public ThiefLisp_Expr{
    public:
            TL_Variable(std::string variableName)
            :_variName(variableName)
            {

            }
            void parsedCompleted();
    private:
            std::string _variName;
    };
    
    
    class TL_AST{
    public:
            TL_AST(bool isAtom,std::string funcName,std::vector<ThiefLisp_Expr>* AllElements)
            :_isAtom(isAtom),_funcName(funcName),_allElements(AllElements)
            {

            }
            
            TL_AST(bool isAtom,ThiefLisp_Expr* element)
            :_isAtom(isAtom),_mainExpr(std::move(element))
            {
                    
            }

            void clear()
            {
                if (_allElements)
                {
                    delete [] _allElements;
                    _allElements= nullptr;
                }


                if(_mainExpr)
                {
                    delete _mainExpr;
                    _mainExpr= nullptr;
                }
            }

        ~TL_AST()
        {
            if (_allElements)
            {
                delete [] _allElements;
                _allElements= nullptr;
            }


            if(_mainExpr)
            {
                delete _mainExpr;
                _mainExpr= nullptr;
            }
        }

            void setRoot();
    private:
            bool _isAtom;
            std::string _funcName;
            ThiefLisp_Expr* _mainExpr;
            std::vector<ThiefLisp_Expr>* _allElements;
    };

}


#endif //READ_LINE_TEST_THIEFLISP_EXPR_H
