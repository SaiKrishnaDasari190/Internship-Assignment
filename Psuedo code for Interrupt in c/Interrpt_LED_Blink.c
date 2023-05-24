#include<stdint.h>
#include "stm32f4xx.h"
#include "Board_LED.h"
#include "Board_Buttons.h"

static void delay(void)
{	
	uint32_t i=0;
	for(i=0;i<=50000;i++);
}

int main(void)
{
	// Initialize LED
	led_init();
	
	//Enable clock for GPIOA
	_HAL_RCC_GPIOA_CLK_ENABLE();

	//Configuring GPIO Interrupt
	hal_gpio_configure_interrupt(GPIO_BUTTON_PIN, INT_FALLING_EDGE);
	
	//Enabling GPIO Interrupt
	hal_gpio_enable_interrupt(GPIO_BUTTON_PIN,EXTIO-IRQn);
	
	while(1)
	{


	}

	return 0;
}

//Whenever the Button pressed the interrupt comes to IRQ Handler 

void EXTI0_IRQ_HANDLER(void)
{
		//Clear the Pending Request (PR) register of the EXTI interrpt Handler
		//to make sure no infinite inyterrupt request 

		EXTI->PR |= EXTI_PR_PR0;

	    //Blinking On Board LED
		LED_On(0);
		delay();
		LED_Off(0);
		delay();
}
