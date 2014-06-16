#ifndef _RAY_H_
#define _RAY_H_

#include "Vector.h"
#include <stdlib.h>

typedef struct Ray {
    Vector origin;
    Vector direction;
} Ray;

Ray createRay(Vector origin, Vector direction);
Vector pointOnRay(Ray ray, float t);

#endif
