#ifndef STYLED_TEXT_TEXT_H_
#define STYLED_TEXT_TEXT_H_

#include "style_node.h"
#include "node.h"

namespace StyledText {

    typedef StyleNode Text;

    template<typename... T>
    Text& blank(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE), args...);
    }

    template<typename... T>
    Text& black(T&... args) {
        return text(CStyle(CStyle::COLOR_BLACK), args...);
    }

    template<typename... T>
    Text& red(T&... args) {
        return text(CStyle(CStyle::COLOR_RED), args...);
    }

    template<typename... T>
    Text& green(T&... args) {
        return text(CStyle(CStyle::COLOR_GREEN), args...);
    }

    template<typename... T>
    Text& yellow(T&... args) {
        return text(CStyle(CStyle::COLOR_YELLOW), args...);
    }

    template<typename... T>
    Text& blue(T&... args) {
        return text(CStyle(CStyle::COLOR_BLUE), args...);
    }

    template<typename... T>
    Text& magenta(T&... args) {
        return text(CStyle(CStyle::COLOR_MAGENTA), args...);
    }

    template<typename... T>
    Text& cyan(T&... args) {
        return text(CStyle(CStyle::COLOR_CYAN), args...);
    }

    template<typename... T>
    Text& white(T&... args) {
        return text(CStyle(CStyle::COLOR_WHITE), args...);
    }

    template<typename... T>
    Text& bold(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BOLD), args...);
    }

    template<typename... T>
    Text& blink(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BLINK), args...);
    }

    template<typename... T>
    Text& underline(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_UNDERLINE), args...);
    }

    template<typename... T>
    Text& negative(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_NEGATIVE), args...);
    }

    template<typename First>
    void concat(Text& node, First& first) {
        node << first;
    }

    template<typename First, typename... Rest>
    void concat(Text& node, First& first, Rest&... rest) {
        node << first << " ";
        concat(node, rest...);
    }

    template<typename... T>
    Text& text(CStyle style, T&... args) {
        Text* sn = new Text(style);
        concat(*sn, args...);
        return *sn;
    }
}

#endif // STYLED_TEXT_TEXT_H_
