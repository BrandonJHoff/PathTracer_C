#include "Material.h"

Material createMaterial(Color color, float Kd, float Ka){
    Material m = {color, Kd, Ka};
    return m;
}

Color shadeWithMaterial(struct Scene* scene, struct HitRecord* record, Ray ray){
    struct HitRecord temp_record = createHitRecord();
	Vector position = record->point;
    Material material = *record->triangle->material;

	Vector N = record->triangle->normal;
	float costheta = dotVector(N, ray.direction);

	if(costheta > 0){
		N = negateVector(N);
	}

    Color result = {0,0,0};

	for(int i = 0; i < scene->num_lights; i++){
        Vector point_on_light = getPointOnTriangle(&scene->lights[i]);
		Vector light_direction = normalizeVector(minusVectorByVector(point_on_light, position));
		Color light_color = scene->lights[i].material->color;

		Ray shadow_ray = {position, light_direction};

        resetHitRecord(&temp_record);
        temp_record.t = distanceBetweenVectors(point_on_light, position);

        float cosphi = dotVector(N, light_direction);

		if(cosphi > 0){
            for(int k = 0; k < scene->num_triangles; k++){
                hitTriangle(&scene->triangles[k], &temp_record, shadow_ray);
            }

            if(!temp_record.has_hit){
				result = addColors(result, multiplyColorByNumber(light_color, material.Kd * cosphi));
			}
		}
	}

	return multiplyColors(result, material.color);
}
