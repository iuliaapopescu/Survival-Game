#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cstring>

#include "Agent.h"

using namespace std;

class Map{
    char **map;
    vector <Agent*> agents;
    vector <Item*> items;
    int dimension;
public:
    Map();

    Map(int);

    ~Map();

    void generateAgents();

    void generateItems();

    void display();

    void play();
};

#endif // MAP_H
