#include "Camera.h"

Camera createCamera(Vector _position, Vector look_at, Vector up, float angle, float aspect){
    Vector g = minusVectorByVector(look_at, _position);
    g = normalizeVector(g);
    Vector u = crossVector(g, up);
    Vector v = crossVector(u, g);

    u = normalizeVector(u);
    v = normalizeVector(v);
    u = multiplyVectorByNumber(u, tan((angle/2.0)*M_PI/180.0));
    v = multiplyVectorByNumber(v, tan((angle/2.0)*M_PI/180.0)/aspect);

	Camera camera = {_position, g, u, v};
    return camera;
}

Ray cameraCreateRay(Camera camera, double x, double y){
    Ray ray;
    ray.origin = camera.position;
    ray.direction = addVectorByVector(addVectorByVector(camera.g, multiplyVectorByNumber(camera.u, x)), multiplyVectorByNumber(camera.v, y));
    ray.direction = normalizeVector(ray.direction);
    return ray;
}
