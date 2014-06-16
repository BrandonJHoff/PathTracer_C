#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Vector.h"
#include "HitRecord.h"
#include "Ray.h"
#include "Color.h"
#include "Scene.h"

struct Scene;
struct HitRecord;

typedef struct Material {
    Color color;
    float Kd;
    float Ka;
} Material;

Material createMaterial(Color color, float Kd, float Ka);
Color shadeWithMaterial(struct Scene* scene, struct HitRecord* record, Ray ray);

#endif
