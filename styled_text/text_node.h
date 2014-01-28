#ifndef STYLED_TEXT_TEXT_NODE_H_
#define STYLED_TEXT_TEXT_NODE_H_

#include <string>
#include "node.h"

namespace StyledText {
    class TextNode : public Node {
        public:
            TextNode(std::string text);
            std::string getText() const { return mText; }

        private:
            std::string mText;
    };
}

#endif // STYLED_TEXT_TEXT_NODE_H_
