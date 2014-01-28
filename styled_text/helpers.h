#ifndef STYLED_TEXT_HELPERS_H_
#define STYLED_TEXT_HELPERS_H_

#include "style_node.h"
#include "node.h"

namespace StyledText {

    typedef StyleNode Text;

    template<typename... T>
    StyleNode& blank(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE), args...);
    }

    template<typename... T>
    StyleNode& black(T&... args) {
        return text(CStyle(CStyle::COLOR_BLACK), args...);
    }

    template<typename... T>
    StyleNode& red(T&... args) {
        return text(CStyle(CStyle::COLOR_RED), args...);
    }

    template<typename... T>
    StyleNode& green(T&... args) {
        return text(CStyle(CStyle::COLOR_GREEN), args...);
    }

    template<typename... T>
    StyleNode& yellow(T&... args) {
        return text(CStyle(CStyle::COLOR_YELLOW), args...);
    }

    template<typename... T>
    StyleNode& blue(T&... args) {
        return text(CStyle(CStyle::COLOR_BLUE), args...);
    }

    template<typename... T>
    StyleNode& magenta(T&... args) {
        return text(CStyle(CStyle::COLOR_MAGENTA), args...);
    }

    template<typename... T>
    StyleNode& cyan(T&... args) {
        return text(CStyle(CStyle::COLOR_CYAN), args...);
    }

    template<typename... T>
    StyleNode& white(T&... args) {
        return text(CStyle(CStyle::COLOR_WHITE), args...);
    }

    template<typename... T>
    StyleNode& bold(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BOLD), args...);
    }

    template<typename... T>
    StyleNode& blink(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_BLINK), args...);
    }

    template<typename... T>
    StyleNode& underline(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_UNDERLINE), args...);
    }

    template<typename... T>
    StyleNode& negative(T&... args) {
        return text(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_NEGATIVE), args...);
    }

    template<typename First>
    void concat(StyleNode& node, First& first) {
        node << first;
    }

    template<typename First, typename... Rest>
    void concat(StyleNode& node, First& first, Rest&... rest) {
        node << first << " ";
        concat(node, rest...);
    }

    template<typename... T>
    StyleNode& text(CStyle style, T&... args) {
        StyleNode* sn = new StyleNode(style);
        concat(*sn, args...);
        return *sn;
    }
}

#endif // STYLED_TEXT_HELPERS_H_
