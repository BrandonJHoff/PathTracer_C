#include "HitRecord.h"

HitRecord createHitRecord(){
    HitRecord record = {};
    record.t = MAX_T;
    record.uvw = createVector(0,0,0);
    record.point = createVector(0,0,0);
    record.normal = createVector(0,0,0);
    record.has_hit = false;
    record.triangle = NULL;
    return record;
}

void resetHitRecord(HitRecord* record){
    record->t = MAX_T;
    record->uvw = createVector(0,0,0);
    record->point = createVector(0,0,0);
    record->normal = createVector(0,0,0);
    record->has_hit = false;
    record->triangle = NULL;
}

bool updateHitRecord(HitRecord* record, double hit_t, struct Triangle* triangle, Ray ray){
    if((hit_t > .001) && (hit_t < record->t)){
		record->t = hit_t;
		record->triangle = triangle;
		record->point = pointOnRay(ray, hit_t);
		record->has_hit = true;
		return true;
	}
	return false;
}
