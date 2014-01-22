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
    static bool historyInitialized = false;

    if (!historyInitialized) {
        using_history();
        historyInitialized = true;
    }
    char* line = readline(prompt);
    add_history(line);
    return line;
}
