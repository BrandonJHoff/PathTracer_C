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
bool setImageColor(Image* img, int x, int y, const Color color);
void writeImage(Image* img, char* filename);
void freeImage(Image* img);

#endif
