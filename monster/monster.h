#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>
#include <utility>
#include <map>
#include "../styled_text/text.h"
#include "../attack_result.h"

typedef std::pair<std::string, std::string> Stat;
typedef std::map<std::string, std::string> Stats;

class Monster {
    public:
        void init();
        Stats getStats() const;
        StyledText::Text& getDescription() const;
        bool isAlive() const;
        AttackResult attack();
        AttackResult takeDamage(Damage damage);

    private:
        int health;
};

#endif // MONSTER_H_
