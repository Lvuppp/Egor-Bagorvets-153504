#ifndef PARSER_H
#define PARSER_H
#include<iostream>
#include<string>
#include<regex>

#include<variable.h>
#include<function.h>

using namespace std;

class Parser
{
public:
    Parser();
    Parser(string &&str);

    vector<Variable> getVariables();
    vector<Function> getFunctions();
    vector<int> getComplexStructs();
    vector<pair<int,int>> getChangePosition();
    vector<pair<int,int>> getBranches();



private:
    void findVariables();
    void findFunctions();

    string _str;

    vector<Variable> _variables;
    vector<Function> _functions;

};

#endif // PARSER_H
