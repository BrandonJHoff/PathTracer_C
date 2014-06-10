#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vector.h"
#include "HitRecord.h"
#include "Ray.h"
#include <stdbool.h>

typedef struct Triangle {
    Vector point1;
    Vector point2;
    Vector point3;
    Vector normal;
} Triangle;

bool hitTriangle(Triangle* tri, struct HitRecord* record, Ray* ray);
void calculateTriangleNormal(Triangle* tri);

#endif
