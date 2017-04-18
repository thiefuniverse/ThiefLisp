//
// Created by thief on 17-3-10.
//

#include <memory>
#include "ThiefLisp_Expr.h"
#ifndef READ_LINE_TEST_THIEFLISP_EVALER_H
#define READ_LINE_TEST_THIEFLISP_EVALER_H

#include <string>
namespace ThiefLispSpace{

    class ThiefLisp_Evaler {
    public:
        std::string eval(TL_AST* evalStr);
    };
}



#endif //READ_LINE_TEST_THIEFLISP_EVALER_H
