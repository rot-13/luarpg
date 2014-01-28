#ifndef STYLED_TEXT_NODE_H_
#define STYLED_TEXT_NODE_H_

namespace StyledText {
    enum NodeType {
        Style,
        Text
    }

    class Node {
        public:
            NodeType getType() { return mType; }

        protected:
            Node(NodeType type);

        private:
            NodeType mType;
    };
}

#endif // STYLED_TEXT_NODE_H_
