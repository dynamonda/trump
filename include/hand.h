// hand.h

#ifndef _HAND_
#define _HAND_

enum class HandName : int {
    ROYAL_FLUSH     = 0,
    STRAIGHT_FLUSH  = 1,
    FOUR_OF_A_KIND  = 2,
    FULL_HOUSE      = 3,
    FLUSH           = 4,
    STRAIGHT        = 5,
    THREE_OF_A_KIND = 6,
    TWO_PAIR        = 7,
    ONE_PAIR        = 8,
    NO_PAIR         = 9,
};

class Hand{
private:
    HandName handName;    
    bool IsRoyalFlush(std::vector<std::shared_ptr<Card>> cardList);
    bool IsStraightFlush(std::vector<std::shared_ptr<Card>> cardList);
    bool IsFourOfaKind(std::vector<std::shared_ptr<Card>> cardList);
    bool IsFullHouse(std::vector<std::shared_ptr<Card>> cardList);
    bool IsFlush(std::vector<std::shared_ptr<Card>> cardList);
    bool IsStraight(std::vector<std::shared_ptr<Card>> cardList);
    bool IsThreeOfaKind(std::vector<std::shared_ptr<Card>> cardList);
    bool IsTwoPair(std::vector<std::shared_ptr<Card>> cardList);
    bool IsOnePair(std::vector<std::shared_ptr<Card>> cardList);
    bool IsJoker(std::vector<std::shared_ptr<Card>> cardList);
    std::vector<std::shared_ptr<Card>> copyCardList(std::vector<std::shared_ptr<Card>> cardList);

public:
    Hand();
    Hand(std::vector<std::shared_ptr<Card>> cardList);
    ~Hand();

    std::string ToString();
};

#endif