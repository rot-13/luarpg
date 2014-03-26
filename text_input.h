#ifndef TEXT_INPUT_H_
#define TEXT_INPUT_H_

#include <string>

typedef struct TextInput {
    std::string verb;
    std::string params;

    static const TextInput parseInput(const std::string input);
} TextInput;

#endif // TEXT_INPUT_H_
