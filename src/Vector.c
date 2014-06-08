#include "Vector.h"

float lengthOfVector(Vector* v){
    return sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
}

void normalizeVector(Vector* v){
    *v = divideVectorByNumber(v, lengthOfVector(v));
}

Vector crossVector(Vector* v1, Vector* v2){
    Vector result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;

	return result;
}

float dotVector(Vector* v1, Vector* v2){
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

Vector multiplyVectorByNumber(Vector* v, float num){
    Vector result = {v->x*num, v->y*num, v->z*num};
    return result;
}

Vector divideVectorByNumber(Vector* v, float num){
    Vector result = {v->x/num, v->y/num, v->z/num};
    return result;
}
