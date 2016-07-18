#ifndef RGB_H
#define RGB_H

struct RGB{
    float r;
    float g;
    float b;
};

inline RGB create_color(float r, float g, float b)
{
    RGB rgb;
    rgb.r = r; rgb.g = g; rgb.b = b;
    return rgb;
}

#endif // RGB_H
