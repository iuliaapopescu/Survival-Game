#include "Map.h"
#include "Agent.h"
#include "AgentA.h"
#include "AgentB.h"
#include "AgentC.h"
#include "Common.h"
#include "Rare.h"
#include "Legendary.h"

Map::Map(int dim): dimension(dim) {
    map = new char*[dimension];
    for(int i = 0; i < dimension; i++)
        map[i] = new char[dimension];
    for(int i = 0; i < dimension; i++)
        for(int j = 0; j < dimension; j++)
            map[i][j] = '.';
    }

Map::Map(){
    dimension = 15;
    map = new char*[dimension];
    for(int i = 0; i < dimension; i++)
        map[i] = new char[dimension];
    for(int i = 0; i < dimension; i++)
        for(int j = 0; j < dimension; j++)
            map[i][j] = '.';
    }

void Map::generateAgents() {
    int desiredA, desiredB, desiredC;

    cout << "Enter number of A agents (at least 7):\n";
    cin >> desiredA;
    while(desiredA < 7){
        cout << "Invalid number, try again:\n> ";
        cin >> desiredA;
    }
    cout << "Enter number of B agents (at least 7):\n";
    cin >> desiredB;
    while(desiredB < 7){
        cout << "Invalid number, try again:\n> ";
        cin >> desiredB;
    }
    cout << "Enter number of C agents (at least 7):\n";
    cin >> desiredC;
    while(desiredC < 7){
        cout << "Invalid number, try again:\n> ";
        cin >> desiredC;
    }

    int numberOfAAgents = 0;
    int numberOfBAgents = 0;
    int numberOfCAgents = 0;

    for(int i = 0; i < desiredA; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Agent *ptr = new AgentA;
        ptr->setX(x);
        ptr->setY(y);
        map[x][y] = ptr->getSymbol();
        agents.emplace_back(ptr);
        numberOfAAgents++;
    }

    for(int i = 0; i < desiredB; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Agent *ptr = new AgentB;
        ptr->setX(x);
        ptr->setY(y);
        map[x][y] = ptr->getSymbol();
        agents.emplace_back(ptr);
        numberOfBAgents++;
    }

    for(int i = 0; i < desiredC; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Agent *ptr = new AgentC;
        ptr->setX(x);
        ptr->setY(y);
        map[x][y] = ptr->getSymbol();
        agents.emplace_back(ptr);
        numberOfCAgents++;
    }

    cout << "\n";
    cout << "> There are " << numberOfAAgents << " A agents\n";
    cout << "> There are " << numberOfBAgents << " B agents\n";
    cout << "> There are " << numberOfCAgents << " C agents\n";
}

void Map::display() {
    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            cout << map[i][j] << ' ';
        cout << endl;
    }
}

void Map::play(){
    string enter;
    int round = 0;

    cout << "Game stats:\n";
    cout << "The grid is: " << dimension << "x" << dimension << " \n";

    generateAgents();
    generateItems();

    cout << "\nEnter any character to start:\n";
    cin >> enter;
    display();

    while(agents.size() > 1){
        for(int i = 0; i < dimension; i++)
            for(int j = 0; j < dimension; j++)
                if(isalpha(map[i][j]) && agents.size() > 1){
                    for(Agent *ptr : agents)
                        if(ptr->getX() == i && ptr->getY() == j){
                            cout << "Enter any character for next round:\n";
                            cin >> enter;
                            cout << "ROUND " << round << ":\n";
                            ptr->move(agents, items, map, dimension);
                            round++;
                            break;
                        }
                    display();
                }
    }

    Agent* ptr = agents[0];
    cout << "Agent " << ptr->getSymbol() << " on position " << ptr->getX() << ' ' << ptr->getY() << " has won!\n";
}

Map::~Map() {
    for(Agent *ptr : agents)
        delete ptr;
    for(Item *ptr: items)
        delete ptr;
    for(int i = 0; i < dimension; i++)
        delete [] map[i];
    delete [] map;
    cout << "Destructor called\n";
}

void Map::generateItems() {
    int commonItems, rareItems, legendaryItems;

    cout << "Enter number of common items, maximum half of the number of agents:\n";
    cin >> commonItems;
    while(commonItems > agents.size()/2){
        cout << "Invalid number, try again:\n> ";
        cin >> commonItems;
    }
    cout << "Enter number of rare items, maximum a third of the number of the agents:\n";
    cin >> rareItems;
    while(rareItems > agents.size()/3){
        cout << "Invalid number, try again:\n> ";
        cin >> rareItems;
    }
    cout << "Enter number of legendary items, maximum a quarter of the number of the agents:\n";
    cin >> legendaryItems;
    while(legendaryItems > agents.size()/4){
        cout << "Invalid number, try again:\n> ";
        cin >> legendaryItems;
    }

    for(int i = 0; i < commonItems; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Item *ptr = new Common;
        map[x][y] = ptr->getSymbol();
        delete ptr;

    }
    Item *common = new Common;
    items.emplace_back(common);

    for(int i = 0; i < rareItems; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Item *ptr = new Rare;
        map[x][y] = ptr->getSymbol();
        delete ptr;
    }
    Item *rare = new Rare;
    items.emplace_back(rare);

    for(int i = 0; i < legendaryItems; i++) {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, dimension - 1);
        int x = distr(eng);
        int y = distr(eng);
        while(map[x][y] != '.') {
            x = distr(eng);
            y = distr(eng);
        }
        Item *ptr = new Legendary;
        map[x][y] = ptr->getSymbol();
        delete ptr;
    }
    Item *legendary = new Legendary;
    items.emplace_back(legendary);

    cout << "> There are " << commonItems << " common items\n";
    cout << "> There are " << rareItems << " rare items\n";
    cout << "> There are " << legendaryItems << " legendary items\n";
}
