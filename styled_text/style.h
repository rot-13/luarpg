#ifndef STYLED_TEXT_STYLE_H_
#define STYLED_TEXT_STYLE_H_

namespace StyledText {
    typedef int Color;
    typedef unsigned int StyleFlag;

    class Style {
        public:
            static const Color COLOR_NONE    = -1;
            static const Color COLOR_BLACK   = 0;
            static const Color COLOR_RED     = 1;
            static const Color COLOR_GREEN   = 2;
            static const Color COLOR_YELLOW  = 3;
            static const Color COLOR_BLUE    = 4;
            static const Color COLOR_MAGENTA = 5;
            static const Color COLOR_CYAN    = 6;
            static const Color COLOR_WHITE   = 7;

            static const StyleFlag FLAG_NONE      = 0b0000;
            static const StyleFlag FLAG_BOLD      = 0b0001;
            static const StyleFlag FLAG_BLINK     = 0b0010;
            static const StyleFlag FLAG_UNDERLINE = 0b0100;
            static const StyleFlag FLAG_NEGATIVE  = 0b1000;

            Style(Color fgColor, Color bgColor, StyleFlag flags);
            Color getFgColor() { return mFgColor; }
            Color getBgColor() { return mBgColor; }
            StyleFlag getFlags() { return mFlags; }
            bool isBold();
            bool isBlink();
            bool isUnderline();
            bool isNegative();

        private:
            Color mFgColor;
            Color mBgColor;
            StyleFlag mFlags;
    };
}

#endif // STYLED_TEXT_STYLE_H_
