#include <vector>
#include <memory>
#include <iostream>

#include <deck.h>
#include <game.h>

Game::Game(){
    gameEndFlag = false;
    std::cout << "Game Created" << std::endl;
}

Game::~Game(){

}

bool Game::setup(){
    std::cout << "Setup Success!" << std::endl;

	std::unique_ptr<Deck> deck = std::make_unique<Deck>();

	deck->shuffle();
	deck->print();

    return true;
}

void Game::update(){
    std::cout << "Game Update" << std::endl;
    gameEndFlag = true;
}

bool Game::isEnd(){
    return gameEndFlag;
}