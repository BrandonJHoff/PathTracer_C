#include "Filter.h"

void applyFilter(Sample* s){
    for(int i = 0; i < s->num_samples; i++){
        float x = s->samples[i].x;
        float y = s->samples[i].y;

        if(x < 0.5){
            s->samples[i].x = sqrt(2.0 * x) - 1.0;
        } else {
            s->samples[i].x = 1.0 - sqrt(2.0 - 2.0 * x);
        }

        if(y < 0.5){
            s->samples[i].y = sqrt(2.0 * y) - 1.0;
        } else {
            s->samples[i].y = 1.0 - sqrt(2.0 - 2.0 * y);
        }
    }
}
