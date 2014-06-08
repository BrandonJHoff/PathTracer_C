#include "../src/Color.h"
#include "../src/Image.h"
#include <stdlib.h>

void createColoredImage(Image* img, Color color){
    img->pixels = malloc(img->width * sizeof(Color));
    for(int i = 0; i < img->width; i++){
        img->pixels[i] = malloc(img->height * sizeof(Color));
        for(int j = 0; j < img->height; j++){
            img->pixels[i][j] = color;
        }
    }
}

int main(){

    Image img = {500, 500, NULL};
    Color color = {1.0, 0.0, 0.0};

    createColoredImage(&img, color);
    writeImage(&img, "test.ppm");
    freeImage(&img);

    return 0;
}
