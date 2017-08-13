#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

#include <cui.h>
#include <game.h>

Parser::Parser(std::string command){
    auto splitCommand = split(command, ' ');
    if(splitCommand.size() > 0){
        auto str = splitCommand[0];
        if(str == "show"){
            if(splitCommand.size() > 1){
                if(splitCommand[1] == "deck"){
                    std::cout << "SHOW DECK COMMAND" << std::endl;
                }
            }else{

            }
        }else if(str == "help"){
            std::cout << "=== Help message ===" << std::endl;
            std::cout << " show deck : print deck list" << std::endl;
            std::cout << " help : print help message" << std::endl;
            std::cout << " exit : end this game" << std::endl;
            std::cout << std::endl;
        }else if(str == "exit"){
            std::cout << "=== Exit message ===" << std::endl;
        }else{
            std::cout << "Error, not exist command: " << str << std::endl;
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

void Parser::evaluate(Game* const game){
    
}

CUI::CUI(){
    this->player = nullptr;
    std::cout << "CUI Created" << std::endl;
}

CUI::~CUI(){

}

void CUI::waitCommand(Game* const game){
    std::string command;
    std::cout << "> ";
    std::getline(std::cin, command);
    std::unique_ptr<Parser> parser = std::make_unique<Parser>(command);
    parser->evaluate(game);

    std::cout << std::boolalpha << game->isEnd() << std::endl;
}