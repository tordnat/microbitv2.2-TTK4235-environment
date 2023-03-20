#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*)0x50000000) //gpio base adress
#define GPIO1 ((NRF_GPIO_REGS1*)0x50000300) //gpio base adress

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
	volatile uint32_t RESERVED1[118];
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
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

void gpio_init(){
	  GPIO0->PIN_CNF[14] = 0;
	  GPIO0->PIN_CNF[23] = 0; 
	  GPIO0->PIN_CNF[21] = 1;
	  GPIO0->PIN_CNF[22] = 1;
	  GPIO0->PIN_CNF[15] = 1;
	  GPIO0->PIN_CNF[24] = 1;
	  GPIO0->PIN_CNF[19] = 1;
	  GPIO0->PIN_CNF[28] = 1;
	  GPIO0->PIN_CNF[11] = 1;
	  GPIO0->PIN_CNF[31] = 1;
	  GPIO1->PIN_CNF[5] = 1;
	  GPIO0->PIN_CNF[30] = 1;
};

void gpio_lights_on(){
   GPIO0->OUTSET = (1<<21);
   GPIO0->OUTSET = (1<<22);
   GPIO0->OUTSET = (1<<15);
   GPIO0->OUTSET = (1<<24);
   GPIO0->OUTSET = (1<<19);
};

void gpio_lights_off(){
   GPIO0->OUTCLR = (1<<21);
   GPIO0->OUTCLR = (1<<22);
   GPIO0->OUTCLR = (1<<15);
   GPIO0->OUTCLR = (1<<24);
   GPIO0->OUTCLR = (1<<19);
};


int main(){
	
	// Configure buttons and leds
	gpio_init();
	
	int sleep = 0;
	while(1){
		sleep = 10000;
		gpio_lights_on();
		while(--sleep);
	}
	return 0;
}
