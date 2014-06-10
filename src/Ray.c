#include "Ray.h"

Vector pointOnRay(Ray r, float t){
    return addVectorByVector(r.origin, multiplyVectorByNumber(r.direction, t));
}
