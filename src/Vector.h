#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>
#include <stdio.h>

typedef struct Vector {
    float x;
    float y;
    float z;
} Vector;

Vector createVector(float _x, float _y, float _z);

float lengthOfVector(Vector v);
Vector normalizeVector(Vector v);
Vector crossVector(Vector v1, Vector v2);
float dotVector(Vector v1, Vector v2);
Vector negateVector(Vector v);
float distanceBetweenVectors(Vector v1, Vector v2);

Vector addVectorByVector(Vector v1, Vector v2);
Vector minusVectorByVector(Vector v1, Vector v2);
Vector multiplyVectorByNumber(Vector v, float num);
Vector divideVectorByNumber(Vector v, float num);



#endif
