#include "Triangle.h"

bool hitTriangle(Triangle* tri, HitRecord* record, Ray* ray){

	Vector edge1 = minusVectorByVector(tri->point1, tri->point3);
	Vector edge2 = minusVectorByVector(tri->point2, tri->point3);
	Vector r1 = crossVector(ray->direction, edge2);

	float denom = dotVector(edge1, r1);

	if(fabs(denom) < 0.00000001){
		return false;
	}

	float invDenom = 1/denom;

	Vector s = minusVectorByVector(ray->origin, tri->point3);
	float b1 = dotVector(s, r1)*invDenom;

	if((b1 < 0) || (b1 > 1)){
		return false;
	}

	Vector r2 = crossVector(s, edge1);
	float b2 = dotVector(ray->direction, r2)*invDenom;

	if((b2 < 0) || ((b1 + b2) > 1)){
		return false;
	}

	float t = dotVector(edge2, r2)*invDenom;

	if(updateHitRecord(record, t, tri, ray)){
		record->uvw.x = b1;
		record->uvw.y = b2;
		record->uvw.z = 1 - b1 - b2;
        record->uvw = normalizeVector(record->uvw);
		return true;
	}

	return false;
}

void calculateTriangleNormal(Triangle* tri){
    tri->normal = crossVector(minusVectorByVector(tri->point1, tri->point3), minusVectorByVector(tri->point2, tri->point3));
    tri->normal = normalizeVector(tri->normal);
}