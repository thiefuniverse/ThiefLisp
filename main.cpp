#include <iostream>
#include <string>
#include <regex>
#include "ThiefLisp.h"

int main() {
    std::regex re("ji");
    std::smatch matchT;
    auto flags = std::regex_constants::match_continuous;
    std::string testStr("(5 ji ji hi ji 8 i)");
    std::regex_search(testStr.cbegin(),testStr.cend(),matchT,re);
    for (auto a=matchT.begin();a!=matchT.end();++a)
    {
   //     std::cout<<a->first.base()<<" **  ";
    }


    ThiefLisp lisper;
    lisper.setHistoryFile("~/.lam_history");
    lisper.setUserName("thief");
    lisper.run();
}