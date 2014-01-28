#ifndef STYLED_TEXT_STYLE_NODE_H_
#define STYLED_TEXT_STYLE_NODE_H_

#include <vector>
#include <iterator>
#include "node.h"
#include "style.h"

namespace StyledText {
    class StyleNode : public Node {
        public:
            StyleNode(Style style);
            Style getStyle() { return mStyle; }

            operator<<(const Node* node);
            std::iterator<const Node*> begin();
            std::iterator<const Node*> end();

        private:
            Style mStyle;
            std::vector<const Node*> mChildren;
    };
}

#endif // STYLED_TEXT_STYLE_NODE_H_
