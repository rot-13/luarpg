#include <sstream>
#include "terminal_renderer.h"

using namespace StyledText;

std::string TerminalRenderer::render(const Node& styledText) {
    TerminalRenderer renderer;

    renderer.parse(&styledText);

    return renderer.getText();
}

void TerminalRenderer::parse(const Node& node) {
    if (node.getType() == NodeType::TextType) {
        appendText(static_cast<const TextNode*>(node));
    } else if (node.getType() == NodeType::StyleType) {
        const StyleNode& styleNode = static_cast<const StyleNode&>(node);
        pushStyle(styleNode.getStyle());
        for (auto iter = styleNode.begin(); iter != styleNode.end(); ++iter) {
            parse((*iter));
        }
        popStyle();
    }
}

void TerminalRenderer::pushStyle(const CStyle& style) {
    CStyle& newStyle = style;
    if (mStyleStack.size() > 0) {
        const CStyle& currentStyle = mStyleStack.back();
        newStyle = createInheritedStyle(style, currentStyle);
    }

    mStyleStack.push_back(newStyle);
    appendStyle(newStyle);
}

void TerminalRenderer::popStyle() {
    //delete mStyleStack.back();
    mStyleStack.pop_back();
    if (mStyleStack.size() > 0) {
        appendStyle(mStyleStack.back());
    } else {
        clearStyle();
    }
}

void TerminalRenderer::appendText(const TextNode* text) {
    mOutput += text->getText();
}

void TerminalRenderer::appendStyle(const CStyle* style) {
    clearStyle();
    mOutput += styleToString(style);
}

void TerminalRenderer::clearStyle() {
    mOutput += "\x1b[0m";
}

CStyle* TerminalRenderer::createInheritedStyle(const CStyle* style, const CStyle* parent) {
    Color fgColor = (style->getFgColor() != CStyle::COLOR_NONE ? style->getFgColor() : parent->getFgColor());
    Color bgColor = (style->getBgColor() != CStyle::COLOR_NONE ? style->getBgColor() : parent->getBgColor());
    StyleFlag flags = style->getFlags() | parent->getFlags();

    return new CStyle(fgColor, bgColor, flags);
}

std::string TerminalRenderer::styleToString(const CStyle* style) {
    std::vector<int> ansiCodes;
    if (style->getFgColor() != CStyle::COLOR_NONE) {
        ansiCodes.push_back(30 + styleColorToANSI(style->getFgColor()));
    }
    if (style->getBgColor() != CStyle::COLOR_NONE) {
        ansiCodes.push_back(40 + styleColorToANSI(style->getBgColor()));
    }
    if (style->isBold()) {
        ansiCodes.push_back(1);
    }
    if (style->isBlink()) {
        ansiCodes.push_back(5);
    }
    if (style->isNegative()) {
        ansiCodes.push_back(7);
    }
    if (style->isUnderline()) {
        ansiCodes.push_back(24);
    }
    std::stringstream ss;
    ss << "\x1b[";
    for (int i = 0; i < ansiCodes.size(); ++i) {
        if (i != 0) ss << ";";
        ss << ansiCodes[i];
    }
    ss << "m";
    return ss.str();
}

int TerminalRenderer::styleColorToANSI(Color color) {
    switch (color) {
        case CStyle::COLOR_BLACK:
            return 0;
            break;
        case CStyle::COLOR_RED:
            return 1;
            break;
        case CStyle::COLOR_GREEN:
            return 2;
            break;
        case CStyle::COLOR_YELLOW:
            return 3;
            break;
        case CStyle::COLOR_BLUE:
            return 4;
            break;
        case CStyle::COLOR_MAGENTA:
            return 5;
            break;
        case CStyle::COLOR_CYAN:
            return 6;
            break;
        case CStyle::COLOR_WHITE:
            return 7;
            break;
        default:
            return -1;
            break;
    }
}
