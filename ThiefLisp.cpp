//
// Created by thief on 17-3-10.
//

// todo:
//     keep state for ThiefLisp
//     load file
#include "ThiefLisp_Utils.h"
#include "ThiefLisp.h"
#include "ThiefLisp_Expr.h"

using namespace ThiefLispSpace;


void ThiefLisp::run() {
    initLisp();
    std::string evalResult;
    TL_AST* readResult;
    while(lispContinue)
    {
        try{
            readResult=reader.readOnce();
            evalResult=evaler.eval(readResult);
        }
        catch (ThiefEmptyInput& erro)
        {
            continue;
        }
        catch (std::string& s)
        {
            evalResult=s;
        }

        printer.print(evalResult);
        if(evalResult==quitStr)
        {
            lispContinue=false;
        }
    }
}

void ThiefLisp::setUserName(const std::string &userName) {
    ThiefLisp::userName = userName;
}

void ThiefLisp::setHistoryFile(const std::string &historyFile) {
    this->historyFile = copyAndFree(tilde_expand(historyFile.c_str()));
    reader.setHistoryFileName(this->historyFile);

}

bool ThiefLisp::loadHistory() {
    return read_history(historyFile.c_str());
}

void ThiefLisp::initLisp() {
    loadHistory();
    inputInfo=userName+">";
}

ThiefLisp::ThiefLisp() {
    lispContinue=true;
}


const std::string ThiefLisp::quitStr="bye";