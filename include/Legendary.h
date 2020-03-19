#ifndef LEGENDARY_H
#define LEGENDARY_H

#include <Item.h>

class Legendary: public Item {
    int increaseLife;
    int increasePower;
    char symbol;
public:
    Legendary();

    int getIncreaseLife() const;

    void setIncreaseLife(int increaseLife);

    int getIncreasePower() const;

    void setIncreasePower(int increasePower);

    char getSymbol() const;

    ~Legendary() {}
};

#endif // LEGENDARY_H
