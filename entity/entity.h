#ifndef ENTITY_H_
#define ENTITY_H_

#include "../styled_text/text.h"

class Entity {
    public:
        enum Type {
            ATTACKABLE,
            USABLE,
            OPENABLE,
            UNLOCKABLE,
            OTHER
        };

        Entity() : mType(Type::OTHER) {}

        Type getType() { return mType; }
        virtual StyledText::Text& describe();

    private:
        Type mType;
};

#endif // ENTITY_H_
