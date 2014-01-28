#ifndef STYLED_TEXT_STYLE_NODE_H_
#define STYLED_TEXT_STYLE_NODE_H_

#include <vector>
#include <iterator>
#include "node.h"
#include "style.h"

namespace StyledText {
    class StyleNode : public Node {
        public:
            StyleNode();
            StyleNode(CStyle style);
            ~StyleNode();
            const CStyle* getStyle() const { return &mStyle; }

            StyleNode& operator<<(const Node& node);
            StyleNode& operator<<(const std::string string);
            std::vector<const Node*>::const_iterator begin() const;
            std::vector<const Node*>::const_iterator end() const;

        private:
            CStyle mStyle;
            std::vector<const Node*> mChildren;
    };
}

#endif // STYLED_TEXT_STYLE_NODE_H_
