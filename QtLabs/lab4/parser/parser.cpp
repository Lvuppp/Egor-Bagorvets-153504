#include "parser.h"
#include <QApplication>

Parser::Parser(string &&str) : _str(str)
{
    findVariables();
    findFunctions();
}

vector<Variable> Parser::getVariables()
{
    return _variables;
}

vector<Function> Parser::getFunctions()
{
    return _functions;
}

void Parser::findFunctions()
{

    smatch sm, sm2,sm3,sm4;

    string str = _str;
    regex reg("(int|float|double|short|long\\slong|char|bool|void|string)\\s+(\\w+)\\s*\\((.*)\\)");
    regex reg2("(int|float|double|short|long\\slong|char|bool|void|string)\\s+\\w*,?");\

    while(regex_search(str,sm,reg)){
        bool isOverload = false;

        for(auto i = 0; i < _functions.size(); i++){
            if(sm[2].str() == _functions[i].getName()){
                isOverload = true;
                break;
            }
        }

        if(isOverload){
            str = sm.suffix();
            continue;
        }

        regex reg2( "(int|float|double|short|long\\slong|char|bool|void|string)");
        regex reg3( "(int|float|double|short|long\\slong|char|bool|void|string)\\s+"+ sm[2].str() +"\\s*\\((.*)\\)");
        vector<pair<int,int>> pos;
        vector<string> args,overloadArgs;
        vector<Function> overloadsFunctions;
        string tmp =sm[3].str();
        auto strTmp = QString::fromStdString(str).split('\n');
        int overloadsCount = 0 ;

        while(regex_search(tmp,sm2,reg2)){
            args.push_back(sm2[1].str());
            tmp = sm2.suffix();
        }

        for(auto i = 0; i < strTmp.length(); i++){
            auto line = strTmp[i].toStdString();

            while(regex_search(line,sm3,reg3)){
                if(overloadsCount != 0){
                    pos.push_back(make_pair(i+1,sm2.position() + 1));

                    string tmp1 = sm3[2].str();
                    overloadArgs.clear();

                    while(regex_search(tmp1,sm4,reg2)){
                        overloadArgs.push_back(sm4[1].str());
                        tmp1 = sm4.suffix();
                    }

                    overloadsFunctions.push_back(Function(sm3[1].str(),sm[2].str(),overloadArgs));
                }
                overloadsCount++;
                line = sm3.suffix();
            }
        }
        _functions.push_back(Function(sm[1].str(), sm[2].str(),overloadsFunctions,args));
        str = sm.suffix();
    }

}

vector<int> Parser::getComplexStructs()
{
    smatch classMatch, structMatch,arrayMatch,staticArruy;

    regex classReg("(class)\\s+(\\w+)\\s*\\{");
    regex structReg("(struct)\\s+(\\w+)\\s*\\{");
    regex arrayReg("(\\w+)\\s*[*]\\s*(\\w+)\\s*[=]\\s*(new)\\s*(\\w+)\\s*(\\[)\\s*(\\w+|\\d+)\\s*(\\])");
    regex staticArrayReg("(int|float|double|short|long\\slong|char|bool|void|string)\\s*(\\w+)\\s*(\\[)\\s*(\\d+)\\s*(\\])");

    vector<int> counter(4);
    string tmp = _str;

    while(regex_search(tmp,classMatch,classReg)){
        tmp = classMatch.suffix();
        counter[0]++;
    }

    tmp = _str;

    while(regex_search(tmp,structMatch,structReg)){
        tmp = structMatch.suffix();
        counter[1]++;
    }

    tmp = _str;

    while(regex_search(tmp,arrayMatch,arrayReg)){
        tmp = arrayMatch.suffix();
        counter[2]++;
    }

    tmp = _str;

    while(regex_search(tmp,staticArruy,staticArrayReg)){
        tmp = staticArruy.suffix();
        counter[3]++;
    }

    return counter;
}

vector<pair<int,int>> Parser::getChangePosition()
{
    smatch sm;
    regex reg("(\\s*(\\S*=\\s*(\\w+))?\\s*;)");
    vector<pair<int,int>> pos;
    auto strTmp = QString::fromStdString(_str).split('\n');
    int varCount = 0;

    for(auto i = 0; i < strTmp.length(); i++){
        auto line = strTmp[i].toStdString();

        while(regex_search(line,sm,reg)){
            if(varCount != 0){
                pos.push_back(make_pair(i+1,sm.position() + 1));
            }
            varCount++;
            line = sm.suffix();
        }
    }
    return pos;
}

vector<pair<int,int>> Parser::getBranches()
{

    smatch sm;
    string inp=_str;
    regex reg("(((if|if else)\\s*(\\()(.*)(\\))\\s*)|else)(\\{)");


    std::vector<int> positions;
    int posit=0;

    while(regex_search(inp,sm,reg)){
        positions.push_back(posit+sm.position(0));

        posit += sm.prefix().length() + sm.length();

        inp = sm.suffix();

    }
    int bracketsCounter;
    vector<pair<int,int>> bracket;

    inp=_str;

    for(int i=0; i<positions.size() ;i++){
        int pos=positions[i];
        bracketsCounter=2;
        pair<int,int> tmp1(pos,bracketsCounter);
        bracket.push_back(tmp1);

        while(bracketsCounter!=1){

            if(positions[i+1]==pos){

                i++;
                bracketsCounter++;
                pair<int,int> tmp(pos,bracketsCounter);
                bracket.push_back(tmp);

            }
            if(inp[pos]=='}'){

                bracketsCounter--;
                pair<int,int> tmp(pos,bracketsCounter);
                bracket.push_back(tmp);

            }
            pos++;
        }
    }

    vector<pair<int,int>> newOne;

    int row=0;
    int column=0;
    int counter=0;


    inp=_str;


    for(int i=0;i<inp.length();i++){

        if(i==bracket[counter].first){
            pair<int,int> tmp(row,bracket[counter].second);
            newOne.push_back(tmp);
            counter++;
        }
        column++;
        if(inp[i]=='\n'){
            row++;
            column=0;
        }
    }
    return newOne;
}

void Parser::findVariables()
{
    regex reg("((int|float|doue|short|long\\slong|char|bool|void|string)\\s(\\w+)\\s*(=\\s*(\\w+))?\\s*;)");
    smatch tmp,tmp2;
    string str = _str;
    int lineSizeTmp= 0;
    while(regex_search(str,tmp,reg)){
        regex reg2(tmp[3].str() + "(\\s*(\\S*=\\s*(\\w+))?\\s*;)");
        vector<pair<int,int>> pos;
        auto strTmp = QString::fromStdString(str).split('\n');
        int varCount = 0;

        for(auto i = 0; i < strTmp.length(); i++){
            auto line = strTmp[i].toStdString();

            while(regex_search(line,tmp2,reg2)){
                if(varCount != 0){
                    pos.push_back(make_pair(i+1,tmp2.position() + 1));
                }
                varCount++;
                line = tmp2.suffix();
            }
        }

        int bracketsCounter = 0;
        qDebug() << tmp.prefix().length();
        for(auto i = 0; i < tmp.prefix().length() + lineSizeTmp; i++){
            if(_str[i] == '{'){
                bracketsCounter++;
            }
            if(_str[i] == '}'){
                bracketsCounter--;
            }

        }
        lineSizeTmp += tmp.prefix().length();

        _variables.push_back(Variable(tmp[2].str(),tmp[3].str(), pos, tmp[5].str(),!bracketsCounter));
        str = tmp.suffix();
    }

}