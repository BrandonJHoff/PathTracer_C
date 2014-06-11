#include "Camera.h"

Camera createCamera(Vector _position, Vector look_at, Vector up, float angle, float aspect){
    float temp_tan = tan((angle/2.0)*M_PI/180.0);

    Vector g = normalizeVector(minusVectorByVector(look_at, _position));
    Vector u = normalizeVector(crossVector(g, up));
    Vector v = normalizeVector(crossVector(u, g));

    u = multiplyVectorByNumber(u, temp_tan);
    v = multiplyVectorByNumber(v, temp_tan/aspect);

	Camera camera = {_position, g, u, v};
    return camera;
}

Ray cameraCreateRay(Camera camera, double x, double y){
    //printf("x: %f y: %f\n", x, y);
    Ray ray;
    ray.origin = camera.position;
    ray.direction = addVectorByVector(addVectorByVector(camera.g, multiplyVectorByNumber(camera.u, x)), multiplyVectorByNumber(camera.v, y));
    ray.direction = normalizeVector(ray.direction);
    return ray;
}
