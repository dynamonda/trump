// deck.h

#ifndef _DECK_
#define _DECK_

class Card;

class Deck{
private:
    int number;
    Card* card;
    std::vector<Card*> cards;

public:
    Deck();
    ~Deck();

    void print();

    int getNumber(){
        return this->number;
    }

    int getCardNumber();
};

#endif