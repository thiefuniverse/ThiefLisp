#include <iostream>
#include "ThiefLisp.h"

int main() {
    ThiefLisp lisper;
    lisper.setHistoryFile("~/.lam_history");
    lisper.setUserName("thief");
    lisper.run();
}