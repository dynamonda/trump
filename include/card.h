// card.h

#ifndef TRUMP_INCLUDE_CARD_H_
#define TRUMP_INCLUDE_CARD_H_

#include <string>

#include "suit.h"
#include "rank.h"

// トランプ1枚を表すクラス
class Card{
private:
    int number_;

public:
    Card(int num);
    ~Card();

    int getNumber();
    Suit getSuit();
    std::string getSuitString();
    Rank getRank();
    std::string getInfoString();
};

#endif