#pragma once

struct Rgb
{
    Rgb(float r, float g, float b) : r(r), g(g), b(b) {}
    float r, g, b;

    unsigned int toRgba8888()
    {
        int rInt = r * 255;
        int gInt = g * 255;
        int bInt = g * 255;

        int output = 0;
        output += rInt;
        output = output << (4 * 6);
        output |= (gInt << (4 * 4));
        output |= (bInt << (4 * 2));
        output += 255;

        return output;
    }
};
