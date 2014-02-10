#include "console.h"
#include "readline.h"
#include "styled_text/terminal_renderer.h"

void Console::print(const StyledText::Text& text) {
    print(StyledText::TerminalRenderer::render(text));
}

void Console::print(const std::string string) {
    std::cout << string << std::endl;
}

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
    if (line && *line) {
        add_history(line);
    }
    return line;
}
