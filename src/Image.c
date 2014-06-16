#include "Image.h"

Image createImage(int width, int height){
	Color black = {0, 0, 0};

	Image img = {width, height, NULL};

	img.pixels = malloc(width * sizeof(Color));
	for(int i = 0; i < width; i++){
		img.pixels[i] = malloc(height * sizeof(Color));
		for(int j = 0; j < height; j++){
			img.pixels[i][j] = black;
		}
	}

	return img;
}

void destroyImage(Image* img){
	for(int i = 0; i < img->width; i++){
		free(img->pixels[i]);
	}
	free(img->pixels);
}

bool setImageColor(Image* img, int x, int y, Color color){
	if(0 > x || x > img->width) return false;
	if(0 > y || y > img->height) return false;

	img->pixels[x][y] = color;
	return true;
}

void writeImage(Image* img, char* filename){
    FILE* out = fopen(filename, "wb");
    (void) fprintf(out, "P6\n%d %d\n255\n", img->width, img->height);

	for(int j = 0; j < img->height; j++){
		for(int i = 0; i < img->width; i++){
			static unsigned char color[3];
	        color[0] = (unsigned char)(img->pixels[i][j].red * 255);
	        color[1] = (unsigned char)(img->pixels[i][j].green * 255);
	        color[2] = (unsigned char)(img->pixels[i][j].blue * 255);
	        (void) fwrite(color, 1, 3, out);
		}
	}

	(void) fclose(out);
	return;
}
