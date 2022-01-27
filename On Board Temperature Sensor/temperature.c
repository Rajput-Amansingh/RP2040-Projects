#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// Core 0 Main Code
int main(void){
    //Initialize all the IO's
    stdio_init_all();

    // Configure ADC
    adc_init();                                             //Initialize the Picos's ADC
    adc_set_temp_sensor_enabled(true);                      // Enable the ADC
    adc_select_input(4);                                    // Pico's Temperature sensor is at Analog input 4

    // Primary Core 0 Loop
    while(1){
        uint16_t raw = adc_read();                          // Read the RAW unsigned data
        const float conversion_factor = 3.3f / (1<<12);     // Conversion factor for the RAW data
        float result = raw * conversion_factor;             // Convert the RAW data to voltage
        float temp = 27 - (result -0.706)/0.001721;         // Conert the voltage to temperature 
        printf("Pico's Temperature = %f C\n", temp);        // Serial Print the Temperature
        sleep_ms(100);                                      // Delay of 100ms
    }
}