#include <game.h>
#include <iostream>

Game::Game(){
    gameEndFlag = false;
    std::cout << "Game Created" << std::endl;
}

Game::~Game(){

}

bool Game::setup(){
    std::cout << "Setup Success!" << std::endl;
    return true;
}

void Game::update(){
    std::cout << "Game Update" << std::endl;
    gameEndFlag = true;
}

bool Game::isEnd(){
    return gameEndFlag;
}