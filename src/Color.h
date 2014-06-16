#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color {
    float red;
    float green;
    float blue;
} Color;

Color createColor(float _red, float _green, float _blue);
Color addColors(Color c1, Color c2);
Color multiplyColors(Color c1, Color c2);
Color multiplyColorByNumber(Color c, float num);
Color checkColorLevels(Color c);

#endif
