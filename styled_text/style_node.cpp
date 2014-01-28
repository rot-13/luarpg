#include "style_node.h"
#include "text_node.h"

using namespace StyledText;

StyleNode::StyleNode() : Node(NodeType::StyleType), mStyle(CStyle(CStyle::COLOR_NONE, CStyle::COLOR_NONE, CStyle::FLAG_NONE)) {
}

StyleNode::StyleNode(CStyle style) : Node(NodeType::StyleType), mStyle(style) {
}

StyleNode::~StyleNode() {
    while (mChildren.size() > 0) {
        delete mChildren.back();
        mChildren.pop_back();
    }
}

StyleNode& StyleNode::operator<<(const Node& node) {
    mChildren.push_back(&node);
    return *this;
}

StyleNode& StyleNode::operator<<(const std::string string) {
    mChildren.push_back(new TextNode(string));
    return *this;
}

std::vector<const Node*>::const_iterator StyleNode::begin() const {
    return mChildren.begin();
}

std::vector<const Node*>::const_iterator StyleNode::end() const {
    return mChildren.end();
}
