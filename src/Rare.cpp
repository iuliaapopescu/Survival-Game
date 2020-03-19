#include "Rare.h"

Rare::Rare() {
    increaseLife = 5;
    increasePower = 10;
    symbol = '*';
}

int Rare::getIncreaseLife() const {
    return increaseLife;
}

void Rare::setIncreaseLife(int increaseLife) {
    Rare::increaseLife = increaseLife;
}

int Rare::getIncreasePower() const {
    return increasePower;
}

void Rare::setIncreasePower(int increasePower) {
    Rare::increasePower = increasePower;
}

char Rare::getSymbol() const {
    return symbol;
}
