#include "text.h"

StyledText::Text& StyledText::make() {
    Text* sn = new Text(CStyle(CStyle::COLOR_NONE));
    return *sn;
}
