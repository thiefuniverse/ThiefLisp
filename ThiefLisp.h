//
// Created by thief on 17-3-10.
//

#ifndef READ_LINE_TEST_THIEFLISP_H
#define READ_LINE_TEST_THIEFLISP_H

#include <string>
#include <readline/history.h>
#include <readline/tilde.h>
#include <readline/readline.h>
#include "ThiefLisp_Reader.h"
#include "ThiefLisp_Evaler.h"
#include "ThiefLisp_Printer.h"


class ThiefLisp {
public:
    static const std::string quitStr;
    ThiefLisp();
    void run();

public:
    void setUserName(const std::string &userName);

    void setHistoryFile(const std::string &historyFile);

private:
    bool loadHistory();
    void initLisp();

    std::string userName;
    std::string historyFile;
    std::string inputInfo;
    bool lispContinue;
    ThiefLisp_Reader reader;
    ThiefLisp_Evaler evaler;
    ThiefLisp_Printer printer;
};


#endif //READ_LINE_TEST_THIEFLISP_H
