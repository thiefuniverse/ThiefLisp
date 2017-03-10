//
// Created by thief on 17-3-10.
//

#include "ThiefLisp.h"
#include "ThiefLisp_Utils.h"

void ThiefLisp::run() {
    initLisp();
    while(lispContinue)
    {
        std::string readResult=reader.readOnce(inputInfo);
        std::string evalResult=evaler.eval(readResult);
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