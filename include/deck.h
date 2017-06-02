// deck.h

#ifndef _DECK_
#define _DECK_

class Deck{
private:
    int number;
public:
    Deck();
    ~Deck();

    int getNumber(){
        return this->number;
    }
};

#endif