#pragma once

namespace Colors{
    // Todo replace float by int arithmetic...
    class RGB;
    class HSV;

    class RGB{
        public:
            float r;
            float g;
            float b;

            RGB();
            RGB(float r, float g, float b);

            HSV toHSV();
    };

    class HSV{
        public:
            float h;
            float s;
            float v;

            HSV();
            HSV(float h, float s, float v);

            RGB toRGB();
    };
}

