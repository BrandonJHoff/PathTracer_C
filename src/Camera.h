#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vector.h"
#include "Ray.h"
#include <math.h>

typedef struct Camera {
    Vector position;
    Vector g;
    Vector u;
    Vector v;
} Camera;

Camera createCamera(Vector _position, Vector look_at, Vector up, float angle, float aspect);
Ray cameraCreateRay(Camera camera, double x, double y);

#endif
