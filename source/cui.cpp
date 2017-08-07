#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

#include <cui.h>
#include <game.h>

void Expression_Exit::interpret(std::stack<int> stack){
    std::cout << "=== Exit message ===" << std::endl;
}

Parser::Parser(std::string command){
    auto splitCommand = split(command, ' ');
    for(std::string str : splitCommand){
        std::cout << str << std::endl;
        if(str == "help"){

        }else if(str == "exit"){
            parseTree.push_back(std::make_shared<Expression_Exit>());
        }else{

        }
    }
}

Parser::~Parser(){

}

std::vector<std::string> Parser::split(const std::string &str, char sep){
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while(std::getline(ss, buffer, sep)){
        v.push_back(buffer);
    }
    return v;
}

void Parser::evaluate(){
    std::stack<int> stack;
    for(auto exp : parseTree){
        exp->interpret(stack);
    }
}

CUI::CUI(){
    std::cout << "CUI Created" << std::endl;
}

CUI::~CUI(){

}

void CUI::waitCommand(Game* const game){
    std::string command;
    std::cout << "> ";
    std::getline(std::cin, command);
    std::unique_ptr<Parser> parser = std::make_unique<Parser>(command);
    parser->evaluate();

    std::cout << std::boolalpha << game->isEnd() << std::endl;
}