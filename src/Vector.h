#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>

typedef struct Vector {
    float x;
    float y;
    float z;
} Vector;

float lengthOfVector(Vector* v);
void normalizeVector(Vector* v);
Vector crossVector(Vector* v1, Vector* v2);
float dotVector(Vector* v1, Vector* v2);

Vector divideVectorByNumber(Vector* v, float num);


#endif
