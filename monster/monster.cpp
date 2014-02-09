#include "monster.h"
#include <sstream>

void Monster::init() {
    this->health = 50;
}

Stats Monster::getStats() const {
    Stats stats;
    stats.insert({ std::string("health"), std::to_string(this->health) });
    return stats;
}

StyledText::Text& Monster::getDescription() const {
    return StyledText::text("Large monster");
}

bool Monster::isAlive() const {
    return this->health > 0;
}

AttackResult Monster::attack() {
    return { 10, StyledText::text("The monster", StyledText::green("farts"), "in your general direction") };
}

AttackResult Monster::takeDamage(Damage damage) {
    if (damage > this->health) {
        damage = this->health;
        this->health = 0;
    } else {
        this->health -= damage;
    }
    return { damage, StyledText::text("The monster takes", StyledText::red(std::to_string(damage)), "points of damage") };
}
