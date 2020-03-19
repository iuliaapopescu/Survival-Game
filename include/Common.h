#ifndef COMMON_H
#define COMMON_H

#include <Item.h>

class Common: public Item {
    int increaseLife;
    int increasePower;
    char symbol;
public:
    Common();

    int getIncreaseLife() const;

    void setIncreaseLife(int increaseLife);

    int getIncreasePower() const;

    void setIncreasePower(int increasePower);

    char getSymbol() const;

    ~Common() {}
};

#endif // COMMON_H
