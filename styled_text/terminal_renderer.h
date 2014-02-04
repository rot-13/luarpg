#ifndef STYLED_TEXT_TERMINAL_RENDERER_H_
#define STYLED_TEXT_TERMINAL_RENDERER_H_

#include <vector>
#include <string>
#include "node.h"
#include "style_node.h"
#include "text_node.h"

namespace StyledText {
    class TerminalRenderer {
        public:
            static std::string render(const Node& styledText);

        private:
            void parse(const Node& node);
            void pushStyle(const CStyle* style);
            void popStyle();
            void appendText(const TextNode& text);
            void appendStyle(const CStyle* style);
            void clearStyle();

            CStyle* createInheritedStyle(const CStyle* style, const CStyle* parent);
            std::string styleToString(const CStyle* style);
            int styleColorToANSI(int color);
            std::string getText() { return mOutput; }

            std::vector<CStyle*> mStyleStack;
            std::string mOutput;
    };
}

#endif // STYLED_TEXT_TERMINAL_RENDERER_H_
