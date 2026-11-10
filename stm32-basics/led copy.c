#include "stm32f10x.h"

void Delay(unsigned int count) {
    for(; count != 0; count--);
}

int main(void) {
    RCC->APB2ENR |= (1 << 4);   
    GPIOC->CRH &= ~(0xF << 20); 
    GPIOC->CRH |= (0x2 << 20);  

    while(1) {
        GPIOC->ODR &= ~(1 << 13); 
        Delay(1000000);           
        GPIOC->ODR |= (1 << 13);  
        Delay(1000000);           
    }
}