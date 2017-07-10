// deck.h

#ifndef _DECK_
#define _DECK_

class Card;

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