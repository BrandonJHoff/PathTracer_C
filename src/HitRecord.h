#ifndef _HITRECORD_H_
#define _HITRECORD_H_

#include "Vector.h"
#include "Ray.h"
#include <stdbool.h>

struct Triangle;

#define MAX_T 100000.0

typedef struct HitRecord {
    double t;
    Vector uvw;
    Vector point;
    Vector normal;
    struct Triangle* triangle;
    bool has_hit;
} HitRecord;

HitRecord createHitRecord();
void resetHitRecord(HitRecord* record);
bool updateHitRecord(HitRecord* record, double hit_t, struct Triangle* triangle, Ray* ray);

#endif
