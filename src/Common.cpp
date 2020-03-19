#include "Common.h"

Common::Common() {
    increaseLife = 5;
    increasePower = 5;
    symbol = '#';
}

int Common::getIncreaseLife() const {
    return increaseLife;
}

void Common::setIncreaseLife(int increaseLife) {
    Common::increaseLife = increaseLife;
}

int Common::getIncreasePower() const {
    return increasePower;
}

void Common::setIncreasePower(int increasePower) {
    Common::increasePower = increasePower;
}

char Common::getSymbol() const {
    return symbol;
}
