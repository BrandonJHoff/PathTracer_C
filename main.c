#include "src/Scene.h"
#include <stdlib.h>

int main(){

    Scene scene = createScene("test.txt");
    renderScene(&scene);
    writeImage(&scene.image, "test.ppm");
    destroyScene(&scene);

    return 0;
}
