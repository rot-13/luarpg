#ifndef STYLED_TEXT_TEXT_H_
#define STYLED_TEXT_TEXT_H_

#include "style_node.h"
#include "node.h"

namespace StyledText {

    typedef StyleNode Text;

    template<typename... T>
    Text& text(const T&... args) {
        return text(CStyle(CStyle::COLOR_NONE), args...);
    }

    template<typename... T>
    Text& black(const T&... args) {
        return text(CStyle(CStyle::COLOR_BLACK), args...);
    }

    template<typename... T>
    Text& red(const T&... args) {
        return text(CStyle(CStyle::COLOR_RED), args...);
    }

    template<typename... T>
    Text& green(const T&... args) {
        return text(CStyle(CStyle::COLOR_GREEN), args...);
    }

    template<typename... T>
    Text& yellow(const T&... args) {
        return text(CStyle(CStyle::COLOR_YELLOW), args...);
    }

    template<typename... T>
    Text& blue(const T&... args) {
        return text(CStyle(CStyle::COLOR_BLUE), args...);
    }

    template<typename... T>
    Text& magenta(const T&... args) {
        return text(CStyle(CStyle::COLOR_MAGENTA), args...);
    }

    template<typename... T>
    Text& cyan(const T&... args) {
        return text(CStyle(CStyle::COLOR_CYAN), args...);
    }

    template<typename... T>
    Text& white(const T&... args) {
        return text(CStyle(CStyle::COLOR_WHITE), args...);
    }

    template<typename... T>
    Text& bold(const T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BOLD), args...);
    }

    template<typename... T>
    Text& blink(const T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BLINK), args...);
    }

    template<typename... T>
    Text& underline(const T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_UNDERLINE), args...);
    }

    template<typename... T>
    Text& negative(const T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_NEGATIVE), args...);
    }

    template<typename First>
    void concat(Text& node, const First& first) {
        node << first;
    }

    template<typename First, typename... Rest>
    void concat(Text& node, const First& first, const Rest&... rest) {
        node << first << " ";
        concat(node, rest...);
    }

    template<typename... T>
    Text& text(CStyle style, const T&... args) {
        Text* sn = new Text(style);
        concat(*sn, args...);
        return *sn;
    }

    Text& make();
}

#endif // STYLED_TEXT_TEXT_H_
