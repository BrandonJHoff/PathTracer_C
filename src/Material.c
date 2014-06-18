#include "Material.h"

Material createMaterial(Color color, float Kd, float Ka, bool is_light){
    Material m = {color, Kd, Ka, is_light};
    return m;
}

Color shadeWithMaterial(struct Scene* scene, struct HitRecord* record, Ray ray, int depth){
    Color result = {0,0,0};
    Material material = *record->triangle->material;
    struct HitRecord temp_record = createHitRecord();
    Vector position = record->point;
    Vector new_direction;

    if(depth == scene->max_depth){
        return result;
    }

    if(material.is_light){
        return material.color;
    }

	Vector normal = record->triangle->normal;
	float costheta = dotVector(normal, ray.direction);

	if(costheta > 0){
		normal = negateVector(normal);
	}

    float path = (double)rand()/(double)RAND_MAX;

    // diffuse BRDF
    if(path < .33){
        new_direction = getDiffuseDirection(normal);
    }
    // BRDF (which is also diffuse)
    else if(path < .66){
        new_direction = getDiffuseDirection(normal);
    }
    // point to light
    else {
         new_direction = getLightDirection(scene, position);
    }

	Ray new_ray = {position, new_direction};
    resetHitRecord(&temp_record);
    float cosphi = dotVector(normal, new_direction);

    if(cosphi > 0){
        result = addColors(result, multiplyColorByNumber(hitScene(scene, &temp_record, new_ray, depth + 1), cosphi));
	}

	return multiplyColors(result, material.color);
}

Vector getDiffuseDirection(Vector normal){
    Vector axis;
    if(fabs(normal.x) < fabs(normal.y) && fabs(normal.x) < fabs(normal.z)){
        axis = createVector(1, 0, 0);
    }
    else if (fabs(normal.y) < fabs(normal.z)){
        axis = createVector(0, 1, 0);
    }
    else{
        axis = createVector(0, 0, 1);
    }

    Vector X = normalizeVector(crossVector(normal, axis));
    Vector Y = normalizeVector(crossVector(normal, X));

    float u = 0;
    float v = 0;
    float u_2 = 0;
    float v_2 = 0;

    do {
        u = (double)rand()/(double)RAND_MAX;
        v = (double)rand()/(double)RAND_MAX;
        u *= 2.0;
        u -= 1.0;
        v *= 2.0;
        v -= 1.0;
        u_2 = u * u;
        v_2 = v * v;
    }
    while((u_2 + v_2) >= 1);

    float w = sqrt(1 - (u_2) - (v_2));

    Vector new_direction = addVectorByVector(multiplyVectorByNumber(X, u), addVectorByVector(multiplyVectorByNumber(Y, v), multiplyVectorByNumber(normal, w)));
    return new_direction;
}

Vector getLightDirection(struct Scene* scene, Vector position){
    int light_index = round(((double)rand()/(double)RAND_MAX) * (scene->num_lights - 1));
    Vector point_on_light = getPointOnTriangle(&scene->lights[light_index]);
    Vector light_direction = normalizeVector(minusVectorByVector(point_on_light, position));
    return light_direction;
}
