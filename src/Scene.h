#ifndef _SCENE_H_
#define _SCENE_H_

#include "Triangle.h"
#include "Camera.h"
#include "Vector.h"
#include "Image.h"

typedef struct Scene {
    Triangle* triangles;
    Camera camera;
    Image image;
    //Sample* samples;
    Triangle* lights;
    int max_depth;
    int num_samples;
    int num_triangles;
    int num_lights;
} Scene;

Scene loadScene(char* filename);
void renderScene(Scene* s);

#endif
