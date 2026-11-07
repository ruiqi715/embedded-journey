#include "stm32f10x.h"//include the device header file,define all registers
//define a simple software delay function

void Delay(unsigned int count) {
    for(; count != 0; count--);//empty loop to consume time
}

int main(void) {
    //1.enable the clock for GPIOC
    //2.RCC->APB2ENR is the APB2 peripheral clock enable register
    //bit 4 controls GPIOC.We setit to 1 provide power to Port C 
    RCC->APB2ENR |= (1 << 4);
    //2.configure PC13 pin as Push-pull output
    //GPIOC->CRH is the Port Configuration High register,managing pins 8 to 15
    //Pin 13 uses bits 20 to 23(4 bits per pin)
    
    //First,clear the 4 bits(20-23)to reset the configuration
    GPIOC->CRH &= ~(0xF << 20); 
    //Then,set the bits to 0010(0x2):
    //Mode=10(Output mode,max speed 2MHz)
    GPIOC->CRH |= (0x2 << 20);  

    //3.Infinite loop to blink the LED
    while(1) {
        //Turn ON the LED
        //GPIOC->ODR is the Output Data Register.Bit 13 controls PC13.
        //For the Blue Pill board,PC13 is active LOW(0=ON)
        //We clear bit 13 to 0 using bitwise AND NOT
        GPIOC->ODR &= ~(1 << 13); 

        //Wait for a while(so the LED stays ON long enough to see)
        Delay(1000000);   
        
        //Turn OFF the LED
        //Set bit 13 to1 using bitwise OR(1=OFF)
        GPIOC->ODR |= (1 << 13);  

        //Wait for a while(so the LED stays OFF long enough to see)
        Delay(1000000);           
    }
}