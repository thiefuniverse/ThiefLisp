//
// Created by thief on 17-3-10.
//
#include <string>
#include "ThiefLisp_Utils.h"

std::string copyAndFree(char* mallocedString)
{
    std::string ret(mallocedString);
    delete mallocedString;
    return ret;
}
