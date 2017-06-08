// deck.h

#ifndef _DECK_
#define _DECK_

class Card;

class Deck{
private:
    int number;
    std::vector<Card*> cards;

public:
    Deck();
    ~Deck();

    void print();

    int getNumber(){
        return this->number;
    }

    void shuffle(int times);
};

#endif