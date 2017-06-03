#include <deck.h>
#include <card.h>

Deck::Deck(){
    cards = new Card(5);
}

Deck::~Deck(){
    delete cards;
}

int Deck::getCardNumber(){
    return this->cards->getNumber();
}