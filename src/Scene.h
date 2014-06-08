#ifndef _SCENE_H_
#define _SCENE_H_

typedef struct Scene {
    Triangle* triangles;
    Camera camera;
    Sample* samples;
    Light* lights;
    int max_depth;
    int num_samples;
} Scene;

void renderScene(Scene* s);
