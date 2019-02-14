/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/




#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include <string.h>
#include <stdlib.h> // for strtoul()
static void nano_wait(int t) {
    asm("       mov r0,%0\n"
        "repeat:\n"
        "       sub r0,#83\n"
        "       bgt repeat\n"
        : : "r"(t) : "r0", "cc");
}


int main(void){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER &= ~0xffffff;
    GPIOA->MODER |= 0x555555;
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    GPIOA->MODER &= ~0xffffff;
    GPIOA->MODER |= 0x555555;
    int change = 0;
	while(1){
		while(change == 0){
			GPIOA->ODR = 0b100100001100;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
		    }
			for(int i=0; i<4;i++){
				nano_wait(1000000000);
				GPIOA->ODR = 0b100100001000;
				nano_wait(1000000000);
				GPIOA->ODR = 0b100100001100;
		    }
			GPIOA->ODR = 0b100100001010;
			for(int i=0; i<3; i++){
				nano_wait(1000000000);
	    	}
			GPIOA->ODR = 0b100100001001;
			nano_wait(1000000000);
			GPIOA->ODR = 0b100100100001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
	    	}
			// left turn
//			GPIOA->ODR = 0b100100001001;
//			for(int i=0; i<5; i++){
//				nano_wait(1000000000);
//	    	}
			GPIOA->ODR = 0b100100100001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
		    }
			for(int i=0; i<4;i++){
				nano_wait(1000000000);
				GPIOA->ODR = 0b100100000001;
				nano_wait(1000000000);
				GPIOA->ODR = 0b100100100001;
		    }
			GPIOA->ODR = 0b100100010001;
			for(int i=0; i<3; i++){
				nano_wait(1000000000);
	    	}
			change = 1;
		}
		while(change == 1){
			GPIOA->ODR = 0b110000001001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
	    	}
			for(int i=0; i<4;i++){
				nano_wait(1000000000);
				GPIOA->ODR = 0b100000001001;
				nano_wait(1000000000);
				GPIOA->ODR = 0b110000001001;
		    }
			GPIOA->ODR = 0b101000001001;
			for(int i=0; i<3; i++){
				nano_wait(1000000000);
	    	}
			GPIOA->ODR = 0b100100001001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
		    }
			// left turn
			GPIOA->ODR = 0b00000110001001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
	    	}
			for(int i=0; i<4;i++){
				nano_wait(1000000000);
				GPIOA->ODR = 0b00000100001001;
				nano_wait(1000000000);
				GPIOA->ODR = 0b00000110001001;
		    }
			GPIOA->ODR = 0b01000101001001;
			for(int i=0; i<3; i++){
				nano_wait(1000000000);
	    	}
			GPIOA->ODR = 0b00100100001001;
			for(int i=0; i<5; i++){
				nano_wait(1000000000);
		    }
			change = 0;
		}
	}
}
