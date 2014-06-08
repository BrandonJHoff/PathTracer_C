#include "Image.h"

bool setImageColor(Image* img, int x, int y, const Color color){
	if(0 > x || x > img->width) return false;
	if(0 > y || y > img->height) return false;

	img->pixels[x][y] = color;
	return true;
}

void writeImage(Image* img, char* filename){

    FILE* out = fopen(filename, "wb");
    (void) fprintf(out, "P6\n%d %d\n255\n", img->width, img->height);

	// int i, j;
	// unsigned int ired, igreen, iblue;
	// unsigned char red, green, blue;
	//
	// for(i = img->height-1; i >= 0; i--){
	// 	for(j = 0; j < img->width; j++){
	// 		ired = (unsigned int)(255 * img->pixels[j][i].red);
	// 		igreen = (unsigned int)(255 * img->pixels[j][i].green);
	// 		iblue = (unsigned int)(255 * img->pixels[j][i].blue);
	// 		if(ired > 255) ired = 255;
	// 		if(igreen > 255) igreen = 255;
	// 		if(iblue > 255) iblue = 255;
	//
    //         static unsigned char color[3];
    //         color[0] = (unsigned char)(ired);
    //         color[1] = (unsigned char)(igreen);
    //         color[2] = (unsigned char)(iblue);
    //         (void) fwrite(color, 1, 3, out);
	// 	}
	// }

	for(int i = 0; i < img->width; i++){
		for(int j = 0; j < img->height; j++){
			static unsigned char color[3];
	        color[0] = (unsigned char)img->pixels[i][j].red;
	        color[1] = (unsigned char)img->pixels[i][j].green;
	        color[2] = (unsigned char)img->pixels[i][j].blue;
	        (void) fwrite(color, 1, 3, out);
		}
	}

	(void) fclose(out);
}

void freeImage(Image* img){
    for(int i = 0; i < img->width; i++){
        free(img->pixels[i]);
    }
    free(img->pixels);
}
