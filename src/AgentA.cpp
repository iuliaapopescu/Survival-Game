#include "AgentA.h"

int AgentA::getPosition(vector <Agent*> agents){
        int position = -1;
        for (Agent *temp : agents) {
            position++;
            if (temp->getX() == x && temp->getY() == y)
                return position;
        }
    }

void AgentA::takeItem(char **map, vector<Item *> &items, int x, int y) {
    if(!isalpha(map[x][y]) && map[x][y] != '.') {
        for (Item *temp : items)
            if (temp->getSymbol() == map[x][y]) {
                map[x][y] = symbol;
                map[AgentA::x][AgentA::y] = '.';
                AgentA::x = x;
                AgentA::y = y;
                power = temp->getIncreasePower();
                life = temp->getIncreaseLife();
                if (life > 100)
                    life = 100;
                cout << "Agent " << getSymbol() << " found an item on position " << x << " " << y << endl;
                return;
            }
    }
}

void AgentA::availablePosition(char **map, int x, int y) {
        if(map[x][y] == '.') {
            cout << "Agent " << getSymbol() << " moved from position " << AgentA::x << ' ' << AgentA::y << " to position " << x << " " << y << endl;
            map[x][y] = symbol;
            map[AgentA::x][AgentA::y] = '.';
            AgentA::x = x;
            AgentA::y = y;
        }
    }

AgentA::AgentA() {
    life = 100;
    power = 25;
    symbol = 'A';
    x = y = -1;
}

AgentA::~AgentA(){}

char AgentA::getSymbol() const {
    return symbol;
}

int AgentA::getLife() const {
    return life;
}

void AgentA::setLife(int life) {
    AgentA::life = life;
}

int AgentA::getPower() const {
    return power;
}

void AgentA::setPower(int power) {
    AgentA::power = power;
}

int AgentA::getX() const {
    return x;
}

void AgentA::setX(int x) {
    AgentA::x = x;
}

int AgentA::getY() const {
    return y;
}

void AgentA::setY(int y) {
    AgentA::y = y;
}

void AgentA::attack(char **map, vector <Agent*> &agents, int newX, int newY) {
        int position = getPosition(agents);
        int opponent = 0;
        if(isalpha(map[newX][newY])) {
            for(Agent *temp : agents) {
                if(temp->getX() == newX && temp->getY() == newY) {
                    if(life > temp->getPower()) {
                        cout << "Agent " << symbol << " on position " << x << ' ' << y << " attacked agent " << temp->getSymbol() << " on position " << newX << ' ' << newY << endl;
                        cout << "Agent " << temp->getSymbol() << " number " << position << " out of " << agents.size() << " has been deleted\n";
                        life-= temp->getPower();
                        map[newX][newY] = symbol;
                        map[x][y] = '.';
                        x = newX; y = newY;
                        agents.erase(agents.begin() + opponent);
                        return;
                    } else {
                        map[x][y] = '.';
                        cout << "Agent " << symbol << " on position " << x << ' ' << y << " lost a fight to agent " << temp->getSymbol() << " on position " << newX << ' ' << newY << endl;
                        cout << "Agent " << symbol << " number " << position << " out of " << agents.size() << " has been deleted\n";
                        agents.erase(agents.begin() + position);
                        return;
                    }
                }
                opponent++;
            }
        }
    }

void AgentA::move(vector <Agent*> &agents, vector <Item*> &items, char **map, int dimension){
    int initialX = x, initialY = y;
    int x1, x2, x3, x4, x5, x6, x7, x8;
    int y1, y2, y3, y4, y5, y6, y7, y8;
    x1 = x - 1; y1 = y - 1; //upper left diagonal
    x2 = x + 1; y2 = y - 1; //down left diagonal
    x3 = x + 1; y3 = y + 1; //down right diagonal
    x4 = x - 1; y4 = y + 1; //upper right diagonal
    x5 = x - 1; y5 = y;     //up
    x6 = x + 1; y6 = y;     //down
    x7 = x; y7 = y - 1;     //left
    x8 = x; y8 = y + 1;     //right

    int nr = agents.size();

    // check for items nearby
    if(x1 > -1 && y1 > -1) {
        takeItem(map, items, x1, y1);
        if (initialX != x || initialY != y)
            return;
    }

    if(x2 < dimension && y2 > -1) {
        takeItem(map, items, x2, y2);
        if(initialX != x || initialY != y)
            return;
    }

    if(x3 < dimension && y3 < dimension) {
        takeItem(map, items, x3, y3);
        if(initialX != x || initialY != y)
            return;
    }

    if(x4 > -1 && y4 < dimension) {
        takeItem(map, items, x4, y4);
        if(initialX != x || initialY != y)
            return;
    }

    if(x5 > -1) {
        takeItem(map, items, x5, y5);
        if (initialX != x || initialY != y)
            return;
    }

    if(x6 < dimension) {
        takeItem(map, items, x6, y6);
        if(initialX != x || initialY != y)
            return;
    }

    if(y7 > -1) {
        takeItem(map, items, x7, y7);
        if(initialX != x || initialY != y)
            return;
    }

    if(y8 < dimension) {
        takeItem(map, items, x8, y8);
        if(initialX != x || initialY != y)
            return;
    }

    // check for opponents to defeat
    if(x1 > -1 && y1 > -1) {
        attack(map, agents, x1, y1);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(x2 < dimension && y2 > -1) {
        attack(map, agents, x2, y2);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(x3 < dimension && y3 < dimension) {
        attack(map, agents, x3, y3);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(x4 > -1 && y4 < dimension) {
        attack(map, agents, x4, y4);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(x5 > -1) {
        attack(map, agents, x5, y5);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(x6 < dimension) {
        attack(map, agents, x6, y6);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(y7 > -1) {
        attack(map, agents, x7, y7);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    if(y8 < dimension) {
        attack(map, agents, x8, y8);
        if(agents.size() != nr)
            return;
        if (initialX != x || initialY != y)
            return;
    }

    // move to available position
    if(x1 > -1 && y1 > -1) {
        availablePosition(map, x1, y1);
        if (initialX != x || initialY != y)
            return;
    }

    if(x2 < dimension && y2 > -1) {
        availablePosition(map, x2, y2);
        if(initialX != x || initialY != y)
            return;
    }

    if(x3 < dimension && y3 < dimension) {
        availablePosition(map, x3, y3);
        if(initialX != x || initialY != y)
            return;
    }

    if(x4 > -1 && y4 < dimension) {
        availablePosition(map, x4, y4);
        if(initialX != x || initialY != y)
            return;
    }

    if(x5 > -1) {
        availablePosition(map, x5, y5);
        if (initialX != x || initialY != y)
            return;
    }

    if(x6 < dimension) {
        availablePosition(map, x6, y6);
        if(initialX != x || initialY != y)
            return;
    }

    if(y7 > -1) {
        availablePosition(map, x7, y7);
        if(initialX != x || initialY != y)
            return;
    }

    if(y8 < dimension) {
        availablePosition(map, x8, y8);
        if(initialX != x || initialY != y)
            return;
    }
}
