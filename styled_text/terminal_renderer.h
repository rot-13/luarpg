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
            static std::string render(const Node* styledText);

        private:
            void parse(const Node* node);
            void pushStyle(const Style* style);
            void popStyle();
            void appendText(const TextNode* text);
            void appendStyle(const Style* style);
            void clearStyle();

            Style* createInheritedStyle(const Style* style, const Style* parent);
            std::string styleToString(const Style* style);
            int styleColorToANSI(int color);
            std::string getText() { return mOutput; }

            std::vector<Style*> mStyleStack;
            std::string mOutput;
    };
}

#endif // STYLED_TEXT_TERMINAL_RENDERER_H_
