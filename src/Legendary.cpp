#include "Legendary.h"

Legendary::Legendary() {
    increaseLife = 15;
    increasePower = 15;
    symbol = '&';
}

int Legendary::getIncreaseLife() const {
    return increaseLife;
}

void Legendary::setIncreaseLife(int increaseLife) {
    Legendary::increaseLife = increaseLife;
}

int Legendary::getIncreasePower() const {
    return increasePower;
}

void Legendary::setIncreasePower(int increasePower) {
    Legendary::increasePower = increasePower;
}

char Legendary::getSymbol() const {
    return symbol;
}
