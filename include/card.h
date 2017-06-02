// card.h

#ifndef _CARD_
#define _CARD_

class Card{
private:
    int number;
public:
    Card(int num);
    ~Card();
    int getNumber();
};

#endif