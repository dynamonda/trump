#include <game.h>
#include <iostream>

Game::Game(){
    gameEndFlag = false;
    std::cout << "Game Created" << std::endl;
}

Game::~Game(){

}

void Game::update(){
    std::cout << "Game Update" << std::endl;
    gameEndFlag = true;
}

bool Game::isEnd(){
    return gameEndFlag;
}