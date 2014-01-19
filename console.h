#include <stdarg.h>

class Console {
    public:
        static void print(const char* line, ...);
        static char* read(const char* prompt);
};
