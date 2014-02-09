#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdarg.h>
#include <string>
#include <iostream>
#include "styled_text/text.h"

class Console {
    public:
        static void print(const StyledText::Text& text);
        static void print(const std::string string);
        static void print(const char* line, ...);
        static char* read(const char* prompt);
};

#endif // CONSOLE_H_
