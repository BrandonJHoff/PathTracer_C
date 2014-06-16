#include "Ray.h"

Ray createRay(Vector origin, Vector direction){
    Ray ray = {origin, direction};
    return ray;
}

Vector pointOnRay(Ray r, float t){
    return addVectorByVector(r.origin, multiplyVectorByNumber(r.direction, t));
}
