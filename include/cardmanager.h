// cardmanager.h

#ifndef _CARDMANAGER_
#define _CARDMANAGER_


class CardManager{
private:
    std::vector<std::shared_ptr<Card>> cards;

public:
    CardManager();
    ~CardManager();

    void print();
};

#endif