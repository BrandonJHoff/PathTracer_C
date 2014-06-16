#ifndef _HITRECORD_H_
#define _HITRECORD_H_

#include "Vector.h"
#include "Ray.h"
#include "Triangle.h"
#include <stdbool.h>
#include <stddef.h>

#define MAX_T 100000.0

struct Triangle;

typedef struct HitRecord {
    Vector uvw;
    Vector point;
    Vector normal;
    struct Triangle* triangle;
    double t;
    bool has_hit;
} HitRecord;

HitRecord createHitRecord();
void resetHitRecord(HitRecord* record);
bool updateHitRecord(HitRecord* record, double hit_t, struct Triangle* triangle, Ray ray);

#endif
