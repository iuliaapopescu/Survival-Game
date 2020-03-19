#ifndef AGENTB_H
#define AGENTB_H

#include <Agent.h>

class AgentB: public Agent {
    int life;
    int power;
    int x, y;
    char symbol;
public:
    AgentB();

    char getSymbol() const;

    int getLife() const;

    void setLife(int life);

    int getPower() const;

    void setPower(int power);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getPosition(vector <Agent*> agents);

    void availablePosition(char **map, int x, int y);

    void takeItem(char **map, vector <Item*> &items, int x, int y);

    void attack(char **map, vector <Agent*> &agents, int newX, int newY);

    void move(vector <Agent*> &agents, vector <Item*> &items, char **map, int dimension);

    ~AgentB();
};

#endif // AGENTB_H
