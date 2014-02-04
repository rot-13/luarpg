#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>
#include <pair>
#include <map>
#include "../styled_text/text.h"

typedef int Damage;

typedef struct {
    Damage damage;
    StyledText::Text& attackText;
} AttackResult;

typedef std::pair<std::string, std::string> Stat;
typedef std::map<std::string, std::string> Stats;

class Monster {
    public:
        void init();
        Stats getStats();
        StyledText::Text& getDescription();
        AttackResult attack();
        AttackResult takeDamage(Damage damage);

    private:
        int health;
};

#endif // MONSTER_H_
