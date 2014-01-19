#include "console.h"
#include "readline.h"

void Console::print(const char* line, ...) {
    va_list args;
    va_start(args, line);
    vprintf(line, args);
    va_end(args);
    printf("\n");
}

char* Console::read(const char* prompt) {
    return readline(prompt);
}
