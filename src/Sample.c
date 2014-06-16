#include "Sample.h"

Sample createSample(int num_samples){
    Sample sample = {};
    sample.num_samples = num_samples;
    sample.samples = malloc(num_samples * sizeof(Vector));
    return sample;
}

void destroy(Sample* sample){
    free(sample->samples);
}

void getSamples(Sample* sample){
    int sqrt_samples = sqrt(sample->num_samples);
	for(int i = 0; i < sqrt_samples; i++) {
		for(int j = 0; j < sqrt_samples; j++) {
			float x = ((double)i + (double)rand()/(double)RAND_MAX) / (double)sqrt_samples;
			float y = ((double)j + (double)rand()/(double)RAND_MAX) / (double)sqrt_samples;
			sample->samples[i*sqrt_samples + j] = createVector(x, y, 0);
		}
	}
}
