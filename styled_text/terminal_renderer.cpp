#include "terminal_renderer.h"

std::string TerminalRenderer::render(const Node* styledText) {
    TerminalRenderer renderer;

    renderer.parse(styledText);

    return renderer.getText();
}

void TerminalRenderer::parse(const Node* node) {
    if (node->getType() == NodeType::Text) {
        appendText(static_cast<const TextNode*>(node));
    } else if (node->getType() == NodeType::Style) {
        const StyleNode *styleNode = static_cast<const StyleNode*>(node);
        pushStyle(styleNode->getStyle());
        for (auto iter = styleNode->begin(); iter != styleNode->end(); ++iter) {
            parse((*iter));
        }
        popStyle();
    }
}

void TerminalRenderer::pushStyle(const Style* style) {
    const Style* currentStyle = mStyleStack.back();

    Style* newStyle = createInheritedStyle(style, currentStyle);

    mStyleStack.push_back(newStyle);
    appendStyle(newStyle);
}

void TerminalRenderer::popStyle() {
    delete mStyleStack.back();
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

void TerminalRenderer::appendStyle(const Style* style) {
    clearStyle();
    mOutput += styleToString(style);
}

void TerminalRenderer::clearStyle() {
    mOutput += "\x1b[0m";
}

Style* TerminalRenderer::createInheritedStyle(const Style* style, const Style* parent) {
    Color fgColor = (style.getFgColor() != COLOR_NONE ? style.getFgColor() : parent.getFgColor());
    Color bgColor = (style.getBgColor() != COLOR_NONE ? style.getBgColor() : parent.getBgColor());
    StyleFlag flags = style.getFlags() | parent.getFlags();

    return new Style(fgColor, bgColor, flags);
}

std::string TerminalRenderer::styleToString(const Style* style) {
    std::vector<int> ansiCodes;
    if (style.getFgColor() != Style::COLOR_NONE) {
        ansiCodes.push_back(30 + styleColorToANSI(style.getFgColor()));
    }
    if (style.getBgColor() != Style::COLOR_NONE) {
        ansiCodes.push_back(40 + styleColorToANSI(style.getBgColor()));
    }
    if (style.isBold()) {
        ansiCodes.push_back(1);
    }
    if (style.isBlink()) {
        ansiCodes.push_back(5);
    }
    if (style.isNegative()) {
        ansiCodes.push_back(7);
    }
    if (style.isUnderline()) {
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
        case Style::COLOR_BLACK:
            return 0;
            break;
        case Style::COLOR_RED:
            return 1;
            break;
        case Style::COLOR_GREEN:
            return 2;
            break;
        case Style::COLOR_YELLO:
            return 3;
            break;
        case Style::COLOR_BLUE:
            return 4;
            break;
        case Style::COLOR_MAGENTA:
            return 5;
            break;
        case Style::COLOR_CYAN:
            return 6;
            break;
        case Style::COLOR_WHITE:
            return 7;
            break;
        default:
            return -1;
            break;
    }
}
