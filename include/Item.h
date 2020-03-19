#ifndef ITEM_H
#define ITEM_H

class Item {
    int increaseLife;
    int increasePower;
    char symbol;
public:
    Item() {}

    virtual void setIncreaseLife(int) = 0;

    virtual int getIncreaseLife() const = 0;

    virtual void setIncreasePower(int) = 0;

    virtual int getIncreasePower() const = 0;

    virtual char getSymbol() const = 0;

    virtual ~Item() {}
};

#endif // ITEM_H
