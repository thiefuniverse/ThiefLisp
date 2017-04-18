//
// Created by thief on 17-3-10.
//

#include "ThiefLisp_Reader.h"
#include "ThiefLisp.h"
#include <memory>


using namespace ThiefLispSpace;

TL_AST* ThiefLisp_Reader::readOnce() {
    auto res=tokeniser.parse();
    std::string readResult("thiefun");
    if (readResult.empty())
    {
        throw ThiefEmptyInput();
    }
    add_history(readResult.c_str());
    append_history(1,historyFileName.c_str());
    return res;
}

void ThiefLisp_Reader::setHistoryFileName(const std::string historyFileName) {
    ThiefLisp_Reader::historyFileName = historyFileName;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
LispTokeniser::LispTokeniser():_listParsing(false) {
    
}

void LispTokeniser::jumpWhiteSpace()
{
    while(_readFlag!=readSource.size()-1)
    {
        if(whiteChars.count(readSource[_readFlag]))
            _readFlag++;
        else
            break;
    }
}

bool LispTokeniser::eof()
{
    return _readFlag==readSource.size()-1;
}

std::string LispTokeniser::parseStr()
{
    std::string res;
    for(_readFlag;_readFlag!=readSource.size();_readFlag++)
    {

        if(whiteChars.count(readSource[_readFlag]))
            return res;
        res+=readSource[_readFlag];
    }
    readSource=readSource.substr(_readFlag,readSource.size()-_readFlag);
    return res;
}

// parse a atom which is a number or variable.
// return a subtree of TL_AST.
TL_AST*  LispTokeniser::parseAtom()
{
    std::string atomStr{parseStr()};

    // judge it's a number or a variable name
    std::smatch matchT;
    auto flags = std::regex_constants::match_continuous;
    std::regex_search(atomStr.cbegin(),atomStr.cend(),matchT,intRegex);

    // it's not a number, parse variable
    if(matchT.empty())
    {
        ThiefLisp_Expr* variEx(new TL_Variable(atomStr));
        variEx->parsedCompleted();
        TL_AST*  res(new TL_AST(true,std::move(variEx)));
        return res;
    }
    else{
        // parse number
        ThiefLisp_Expr* variEx(new TL_Expr_Number(StringToNumebr(atomStr)));
        variEx->parsedCompleted();
        TL_AST*  res(new TL_AST(true,std::move(variEx)));
        return res;
    }

}


std::string LispTokeniser::readAList() {
    std::string alist;
    size_t leftCounter{0},rightCounter{0};
    if(readSource[_readFlag]==leftSyntax)
        leftCounter=1;
    alist+=readSource[_readFlag];

    while(leftCounter>rightCounter)
    {
        _readFlag++;
        if(_readFlag==readSource.size())
        {
            getline(std::cin,readSource);
            _readFlag=0;
        }
       // jumpWhiteSpace();
        alist+=readSource[_readFlag];
        if(readSource[_readFlag]==leftSyntax) leftCounter++;
        else if(readSource[_readFlag]==rightSyntax) rightCounter++;
    }


    return alist;
}



TL_AST* LispTokeniser::parseList()
{
    std::vector<ThiefLisp_Expr>* listEx{nullptr};
    std::string listStr(readAList());
    std::cout<<listStr<<std::endl;
    //auto
    TL_AST*  resAST(new TL_AST(false,"",listEx));
    if(readSource[_readFlag]==rightSyntax)
    {
        _listParsing=false;
    }
    return resAST;
}

TL_AST*  LispTokeniser::parse()
{
    if(readSource.empty())
    {
        getline(std::cin,readSource);  //todo  it will be a bug ? safe?
        _readFlag=0;
    }
    jumpWhiteSpace();

   // if(eof())   ;

    if(readSource[_readFlag]==leftSyntax)
       {
           _listParsing=true;
           parseList();
       }
       else
       {
           //It is a atom. judge it is number or variable [ or others]
           return parseAtom();
       }
}


const std::regex LispTokeniser::intRegex("^[-+]?\\d+$");
const std::regex LispTokeniser::closeRegex("[\\)\\]}]");
const std::regex whitespaceRegex("[\\s,]+|;.*");