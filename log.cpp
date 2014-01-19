#include <stdio.h>
#include "log.h"
#include "console.h"

int Log::mLevel;

void Log::debug(const char *string, ...) {
    va_list args;
    va_start(args, string);
    log("\x1b[37;1mDEBUG", LEVEL_DEBUG, string, args);
    va_end(args);
}

void Log::info(const char *string, ...) {
    va_list args;
    va_start(args, string);
    log("\x1b[36;1mINFO", LEVEL_INFO, string, args);
    va_end(args);
}

void Log::warn(const char *string, ...) {
    va_list args;
    va_start(args, string);
    log("\x1b[33;1mWARN", LEVEL_WARN, string, args);
    va_end(args);
}

void Log::error(const char *string, ...) {
    va_list args;
    va_start(args, string);
    log("\x1b[31;1mERROR", LEVEL_ERROR, string, args);
    va_end(args);
}

void Log::setLevel(int level) {
    mLevel = level;
}

void Log::log(const char *prefix, int level, const char* string, va_list args) {
    if (mLevel <= level) {
        int bufferLength = vsnprintf(NULL, 0, string, args) + 1; // 1 for null-termination
        if (bufferLength > 0) {
            char *msg = new char[bufferLength];
            vsnprintf(msg, bufferLength, string, args);
            Console::print("%s: %s\x1b[0m", prefix, msg);
            delete[] msg;
        }
    }
}
