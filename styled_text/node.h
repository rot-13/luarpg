#ifndef STYLED_TEXT_NODE_H_
#define STYLED_TEXT_NODE_H_

namespace StyledText {
    enum NodeType {
        StyleType,
        TextType
    };

    class Node {
        public:
            NodeType getType() const { return mType; }

        protected:
            Node(NodeType type) : mType(type) {}

        private:
            NodeType mType;
    };
}

#endif // STYLED_TEXT_NODE_H_
