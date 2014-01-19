#include <stdarg.h>

class Log {
    public:
        static const int LEVEL_DEBUG = 0;
        static const int LEVEL_INFO = 1;
        static const int LEVEL_WARN = 2;
        static const int LEVEL_ERROR = 3;

        static void debug(const char *string, ...);
        static void info(const char *string, ...);
        static void warn(const char *string, ...);
        static void error(const char *string, ...);
        static void setLevel(int logLevel);

    private:
        static void log(const char* prefix, int level, const char* string, va_list args);
        static int mLevel;
};
