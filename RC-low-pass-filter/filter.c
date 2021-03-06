#include "filter.h"

/*
*   This function initializes the low pass RC digital filter with the coefficients based on the cut-off frequency given. 
*/
void RCFilter_init(RCFilter *filter, float cutOffFreq_HZ, float sampleTime_S){
    // Calculate 'RC' for given cutoff Frequency : RC = TimeConstant

    float RC = 1.0f/(TWO_PI*cutOffFreq_HZ);

    // Calculate the filter coefficients

    filter->coefficients[0] = sampleTime_S / (sampleTime_S + RC);
    filter->coefficients[1] = RC / (sampleTime_S + RC);

    // Clear the filter output buffers. 

    filter->output_buffer[0] = 0.0; 
    filter->output_buffer[1] =0.0;
}

/*
*       This function gives you the filtered output given the new sample. 
*/
float RCFilter_run(RCFilter *filter, float currentInput){

    // Move last filter output to the previous sample location 
    filter->output_buffer[1] = filter->output_buffer[0];

    // Calculate new output based on given currentInput and previous filter output
    filter->output_buffer[0] = filter->coefficients[0]*currentInput + filter->coefficients[1]*filter->output_buffer[1]; 

    // return the current filter output
    return filter->output_buffer[0];
}

