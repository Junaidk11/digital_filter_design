#ifndef _FILTER_H
#define _FILTER_H  // Include guards


// RC Low-pass Filter structure
typedef struct {
    float coefficients[2];
    float output_buffer[2]; 
}RCFilter; 

// Methods
void RCFilter_init(RCFilter *filter, float cutOffFreq_HZ, float sampleTime_S);
float RCFilter_run(RCFilter *filter, float currentInput); 


#endif