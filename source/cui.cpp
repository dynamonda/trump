#include <iostream>
#include <string>
#include <vector>

#include <cui.h>
#include <game.h>

Parser::Parser(std::string command){
    std::cout << command << std::endl;
}

Parser::~Parser(){

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
    
    std::cout << std::boolalpha << game->isEnd() << std::endl;
}