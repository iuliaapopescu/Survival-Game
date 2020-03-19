#ifndef RARE_H
#define RARE_H

#include <Item.h>

class Rare: public Item {
    int increaseLife;
    int increasePower;
    char symbol;
public:
    Rare();

    int getIncreaseLife() const;

    void setIncreaseLife(int increaseLife);

    int getIncreasePower() const;

    void setIncreasePower(int increasePower);

    char getSymbol() const;

    ~Rare() {}
};

#endif // RARE_H
