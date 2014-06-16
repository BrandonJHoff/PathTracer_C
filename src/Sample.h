#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "Vector.h"
#include <stdlib.h>

typedef struct Sample {
    Vector* samples;
    int num_samples;
} Sample;

Sample createSample(int num_samples);
void destroy(Sample* sample);
void getSamples(Sample* sample);

#endif
