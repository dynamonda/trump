#include <iostream>
#include <string>

#include <cui.h>

Parser::Parser(){

}

Parser::~Parser(){
    
}

CUI::CUI(){
    std::cout << "CUI Created" << std::endl;
}

CUI::~CUI(){

}

void CUI::waitCommand(){
    std::string command;
    std::cout << "> "; 
    std::cin >> command;
    std::cout << command << std::endl;
}