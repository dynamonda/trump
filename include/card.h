// card.h

#ifndef _CARD_
#define _CARD_

class Card{
private:
    int keyNumber;
public:
    Card(int num);
    ~Card();
    
    int getNumber();
};

#endif