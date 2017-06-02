// deck.h

#ifndef _DECK_
#define _DECK_

class Card;

class Deck{
private:
    int number;
    Card* cards;

public:
    Deck();
    ~Deck();

    int getNumber(){
        return this->number;
    }

    int getCardNumber();
};

#endif