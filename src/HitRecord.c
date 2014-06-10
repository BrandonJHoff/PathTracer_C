#include "HitRecord.h"

void resetHitRecord(HitRecord* record){
    record->t = 100000.0;
    record->uvw = (Vector){0, 0, 0};
    record->point = (Vector){0, 0, 0};
    record->normal = (Vector){0, 0, 0};
}

bool updateHitRecord(HitRecord* record, double hit_t, struct Triangle* triangle, Ray* ray){
    if((hit_t > .001) && (hit_t < record->t)){
		record->t = hit_t;
		record->triangle = triangle;
		record->point = pointOnRay(*ray, hit_t);
		//mat = hit_obj->mat;
		return true;
	}
	return false;
}
