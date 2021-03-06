#include "deck.h"

Deck::Deck(){
    for(int i=0; i<=52; ++i){
        auto card = std::make_shared<Card>(i);
        cards.push_back(card);
    }
}

Deck::~Deck(){

}

std::shared_ptr<Card> Deck::draw(){
    if (cards.size() <= 0) {
        return nullptr;
    } else {
        auto i = cards.begin();
        auto card = *i;
        std::shared_ptr<Card> p_card(new Card(*card));
        cards.erase(i);
        return p_card;
    }
}

void Deck::print(){
    for(int i=0; i<cards.size(); ++i){
        int rank = int(cards[i]->getRank());
        std::cout 
            << "[" << i << "]"
            << cards[i]->getSuitString() << ":" 
            << rank
            << std::endl;
    }
}

void Deck::shuffle(int times){
    std::cout << "Shuffle " << times << std::endl;
    std::random_device rnd;
    std::mt19937 mt(rnd());
    if(cards.size() > 0){
        std::uniform_int_distribution<> randCardNum(0, cards.size()-1);
        for(int i=0; i<times; ++i){
            int swp1 = randCardNum(mt);
            int swp2 = randCardNum(mt);
            std::swap(cards[swp1], cards[swp2]);
        }
    }
}