#include <avr/io.h>
#include <avr/interrupt.h> 

#include <stdio.h>
#include "adc.h"

void adc_init() {
    ADMUX = 0x00;
	// Select Vref=AVcc
	ADMUX |= (1 << REFS0);
    //left adjusted
    ADMUX |= (1 << ADLAR);
	//set prescaller to 8 and enable ADC 
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
 
    ADCSRA |= (1 << ADIE); //interrupt
    ADCSRA |= (1 << ADEN); //ENABLE ADC
    sei();
}


int adc_read() {
    int ADCval;
    ADCSRA |= (1 << ADSC); //START ADC

    ADCval = ADCH; //adc value

    return ADCval;
}

//uint16_t ReadADC(uint8_t ADCchannel)
//{
//    //select ADC channel with safety mask
//    ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
//    //single conversion mode
//    ADCSRA |= (1 << ADSC);
//    // wait until ADC conversion is complete
//    while (ADCSRA & (1 << ADSC));
//    return ADC;
//}
//ISR(ADC_vect)
//{
//    {
//        if (ADCH < 128)
//        {
//            PORTE |= (1 << 2); // Turn on LED1
//        }
//
//        else
//        {
//            PORTE &= ~(1 << 2); // Turn off LED1
//        }
//}
