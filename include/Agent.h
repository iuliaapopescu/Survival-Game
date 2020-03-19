#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <iostream>
#include "Item.h"
using namespace std;

class Agent{
    int life;
    int power;
    int x, y;
    char symbol;
public:
    Agent(){}

    virtual char getSymbol() const = 0;

    virtual int getLife() const = 0;

    virtual void setLife(int) = 0;

    virtual int getPower() const = 0;

    virtual void setPower(int) = 0;

    virtual int getX() const = 0;

    virtual void setX(int) = 0;

    virtual int getY() const = 0;

    virtual void setY(int) = 0;

    virtual void move(vector <Agent*>&, vector <Item*>&, char**, int) = 0;

    virtual ~Agent(){}
};

#endif // AGENT_H
