#ifndef ATTACK_RESULT_H_
#define ATTACK_RESULT_H_

#include "styled_text/text.h"

typedef int Damage;

typedef struct {
    Damage damage;
    StyledText::Text& attackText;
} AttackResult;

#endif // ATTACK_RESULT_H_
