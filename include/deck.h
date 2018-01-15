// deck.h

#ifndef TRUMP_INCLUDE_DECK_H_
#define TRUMP_INCLUDE_DECK_H_

#include "card.h"

#include <vector>
#include <memory>
#include <iostream>
#include <utility>
#include <random>
#include <algorithm>

// 山札（カードの束）を表すクラス
class Deck{
private:
    int number;
    std::vector<std::shared_ptr<Card>> cards;

public:
    Deck();
    ~Deck();

    std::shared_ptr<Card> draw();

    void print();

    int getNumber(){
        return this->number;
    }

    void shuffle(int times=100);
};

#endif