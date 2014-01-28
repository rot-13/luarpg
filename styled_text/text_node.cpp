#include "text_node.h"

using namespace StyledText;

TextNode::TextNode(std::string text) : Node(NodeType::TextType), mText(text) {
}
