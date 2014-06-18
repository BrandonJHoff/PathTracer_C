#ifndef _SCENE_H_
#define _SCENE_H_

#include "Camera.h"
#include "Vector.h"
#include "Image.h"
#include "HitRecord.h"
#include "Material.h"
#include "Sample.h"
#include "Filter.h"

struct Material;
struct Triangle;

typedef struct Scene {
    Camera camera;
    Image image;
    struct Triangle* triangles;
    struct Triangle* lights;
    struct Material* materials;
    int max_depth;
    int num_samples;
    int num_triangles;
    int num_lights;
    int num_materials;
} Scene;

Scene createScene(char* filename);
void destroyScene(Scene* scene);
void renderScene(Scene* scene);
Color hitScene(struct Scene* scene, struct HitRecord* record, Ray ray, int depth);

#endif
