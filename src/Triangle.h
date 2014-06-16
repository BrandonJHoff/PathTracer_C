#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vector.h"
#include "Ray.h"
#include "HitRecord.h"
#include <stdbool.h>
#include <stdlib.h>

struct HitRecord;
struct Material;

typedef struct Triangle {
    struct Material* material;
    Vector point1;
    Vector point2;
    Vector point3;
    Vector normal;
} Triangle;

Triangle createTriangle(struct Material* material, Vector point1, Vector point2, Vector point3);
void destroyTriangle(Triangle* tri);
bool hitTriangle(Triangle* tri, struct HitRecord* record, Ray ray);
void calculateTriangleNormal(Triangle* tri);
Vector getPointOnTriangle(Triangle* tri);

#endif
