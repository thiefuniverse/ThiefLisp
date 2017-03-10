//
// Created by thief on 17-3-10.
//

#include "ThiefLisp_Reader.h"

std::string ThiefLisp_Reader::readOnce(std::string& inputInfo) {
    const char* inputIn=inputInfo.c_str();
    std::string readResult(readline(inputIn));
    add_history(readResult.c_str());
    append_history(1,historyFileName.c_str());
    return readResult;
}

void ThiefLisp_Reader::setHistoryFileName(const std::string historyFileName) {
    ThiefLisp_Reader::historyFileName = historyFileName;
}
