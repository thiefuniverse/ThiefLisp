//
// Created by thief on 17-3-10.
//

#ifndef READ_LINE_TEST_THIEFLISP_READER_H
#define READ_LINE_TEST_THIEFLISP_READER_H

#include <string>
#include "ThiefLisp_Expr.h"
#include "ThiefLisp_Utils.h"
#include <regex>
#include <readline/history.h>
#include <readline/tilde.h>
#include <readline/readline.h>
#include <unordered_set>

namespace ThiefLispSpace{

static std::unordered_set<char> whiteChars{'\n','\r',' '};
static char leftSyntax='(';
static char rightSyntax=')';


    class LispTokeniser{
    public:
        LispTokeniser();

        TL_AST* parse();
        TL_AST* parseAtom();
        TL_AST* parseList();
        

        bool eof();

        static const std::regex intRegex;
        static const std::regex closeRegex;

        static const std::regex whitespaceRegex;
    private:
        std::string readAList();
        void jumpWhiteSpace();
        std::string parseStr();
        //std::unique_ptr<>
        
        int _readFlag;
        bool _listParsing;
        std::string readSource;

    };
    
    class ThiefLisp_Reader {
    public:
        TL_AST* readOnce();

    private:
        std::string historyFileName;
        LispTokeniser tokeniser;
        
    public:
        void setHistoryFileName(const std::string historyFileName);

    };



}



#endif //READ_LINE_TEST_THIEFLISP_READER_H
