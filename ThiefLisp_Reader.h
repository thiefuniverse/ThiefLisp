//
// Created by thief on 17-3-10.
//

#ifndef READ_LINE_TEST_THIEFLISP_READER_H
#define READ_LINE_TEST_THIEFLISP_READER_H

#include <string>
#include <readline/history.h>
#include <readline/tilde.h>
#include <readline/readline.h>

class ThiefLisp_Reader {
public:
    std::string readOnce(std::string& inputInfo);

private:
    std::string historyFileName;
public:
    void setHistoryFileName(const std::string historyFileName);

};


#endif //READ_LINE_TEST_THIEFLISP_READER_H
