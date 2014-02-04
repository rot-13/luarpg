#include "style.h"

using namespace StyledText;

CStyle::CStyle(const CStyle& other) :
    mFgColor(other.mFgColor), mBgColor(other.mBgColor), mFlags(other.mFlags) {}

CStyle::CStyle(Color fgColor, Color bgColor, StyleFlag flags) :
    mFgColor(fgColor), mBgColor(bgColor), mFlags(flags) {}

Color CStyle::getFgColor() const {
    return mFgColor;
}

Color CStyle::getBgColor() const {
    return mBgColor;
}

StyleFlag CStyle::getFlags() const {
    return mFlags;
}

bool CStyle::isBold() const {
    return FLAG_BOLD & mFlags;
}

bool CStyle::isBlink() const {
    return FLAG_BLINK & mFlags;
}

bool CStyle::isUnderline() const {
    return FLAG_UNDERLINE & mFlags;
}

bool CStyle::isNegative() const {
    return FLAG_NEGATIVE & mFlags;
}
