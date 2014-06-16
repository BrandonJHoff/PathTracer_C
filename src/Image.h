#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Color.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Image {
    int width;
	int height;
	Color** pixels;
} Image;

Image createImage(int width, int height);
void destroyImage(Image* img);
bool setImageColor(Image* img, int x, int y, Color color);
void writeImage(Image* img, char* filename);

#endif
