#include "Color.h"

Color createColor(float red, float green, float blue){
    Color c = {red, green, blue};
    return c;
}

Color addColors(Color c1, Color c2){
    Color c = {c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue};
    return checkColorLevels(c);
}

Color multiplyColors(Color c1, Color c2){
    Color c = {c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue};
    return checkColorLevels(c);
}

Color multiplyColorByNumber(Color c, float num){
    Color result = {c.red * num, c.green * num, c.blue * num};
    return checkColorLevels(result);
}

Color checkColorLevels(Color c){
    c.red = c.red <= 1.0 ? c.red : 1.0;
    c.green = c.green <= 1.0 ? c.green : 1.0;
    c.blue = c.blue <= 1.0 ? c.blue : 1.0;
    return c;
}
