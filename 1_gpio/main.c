#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*)__GPIO_BASE_ADDRESS__) //gpio 0 base adress
#define GPIO1 ((NRF_GPIO_REGS1*)__GPIO_BASE_ADDRESS__) //gpio 1 base adress

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[__RESERVED1_0_SIZE__];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[__RESERVED1_1_SIZE__];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

int main(){

	// Configure leds (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	__GPIOX__->PIN_CNF[21] = 1; //Row 1
	__GPIOX__->PIN_CNF[22] = 1; //Row 2
	__GPIOX__->PIN_CNF[15] = 1; //Row 3
	__GPIOX__->PIN_CNF[24] = 1; //Row 4
	__GPIOX__->PIN_CNF[19] = 1; //Row 5

	__GPIOX__->PIN_CNF[28] = 1; //Col 1
	__GPIOX__->PIN_CNF[11] = 1; //Col 2
	__GPIOX__->PIN_CNF[31] = 1; //Col 3
	__GPIOX__->PIN_CNF[5] = 1;  //Col 4
	__GPIOX__->PIN_CNF[30] = 1; //Col 5 
	
	// Configure buttons (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	__GPIOX__->PIN_CNF[__BUTTON_A_PIN__] = 0; // button A 
	__GPIOX__->PIN_CNF[__BUTTON_B_PIN__] = 0; // button B
	
	int sleep = 0;
	while(1){

		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
