#ifndef _RAY_H_
#define _RAY_H_

#include "Vector.h"

typedef struct Ray {
    Vector origin;
    Vector direction;
} Ray;

Vector pointOnRay(Ray* r, float t){
    return addVectors(r->origin, multiplyVectorByNumber(r->direction, t));
}
