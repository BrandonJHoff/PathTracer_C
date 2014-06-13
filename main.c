#include "src/Scene.h"
#include <stdlib.h>

int main(){

    Scene scene = loadScene("test.txt");
    renderScene(&scene);
    writeImage(&scene.image, "test.ppm");
    freeImage(&scene.image);

    return 0;
}
