/**********************************************************
@author: LIEK TEAM
@version: 2.4
@date: 01.05.2021
-PWM pins for speed control: A0,A1,...,A7 and B0. Other pwm pins does not work.
-Digital pins for direction: All GPIO pins except A15, B3, B4.
************************************************************/
#include "stm32f10x.h"                  // Device header
#include "dc_motor_library.h"

uint32_t delay_counter = 0;		// The counter for delay function

void systemClockEnable(void){

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock/1000);
}

void SysTick_Handler(void){
    if(delay_counter>0){
        delay_counter--;
    }
}

void Motor_Delay(uint32_t time){		// Real time delay function
	
    systemClockEnable();
    delay_counter=time;
    while(delay_counter);
}

void MotorRun(Motor Port_Pin, uint16_t speed, char direction){   // Running function with pwm

	 uint16_t timPulse = 	24*speed;		// sets the period range between 0 and 100 	
	 
if(direction=='f'){				// motor direction
	
	Port_Pin.forward_port->BSRR = Port_Pin.forward_pin;		// high voltage for forward pin
	Port_Pin.backward_port->BRR = Port_Pin.backward_pin;		// low voltage for backward pin
}
else if(direction=='b'){	// motor direction 
	
	Port_Pin.backward_port->BSRR = Port_Pin.backward_pin;	// high voltage for backward pin
	Port_Pin.forward_port->BRR = Port_Pin.forward_pin;		// low voltage for forward pin
}
	
if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_0){		// running with pwm
	
	TIM2->CCR1 = timPulse;  // CCR = timPulse [Duty Cycle = (CCR/ARR)*100]
	TIM2->EGR |= 0x1; 			// Update generation enable
	TIM2->CR1 |= 0x1;				// Relevant timer enable
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_1){

	TIM2->CCR2= timPulse;  
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |= 0x1;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_2){

	TIM2->CCR3 = timPulse;  
	TIM2->EGR |= 0x1;
	TIM2->CR1 |= 0x1;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_3){

	TIM2->CCR4 = timPulse;  
	TIM2->EGR |= 0x1;
	TIM2->CR1 |= 0x1;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_6){

	TIM3->CCR1 = timPulse;  
	TIM3->EGR |= 0x1; 
	TIM3->CR1 |=0x1;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_7){

	TIM3->CCR2 = timPulse;  
	TIM3->EGR |= 0x1; 
	TIM3->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_8){

	TIM1->CCR1 = timPulse;  
	TIM1->EGR |= 0x1; 
	TIM1->CR1 |=0x1;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_9){

	TIM1->CCR2 = timPulse;  
	TIM1->EGR |= 0x1; 
	TIM1->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_10){

	TIM1->CCR3 = timPulse;  
	TIM1->EGR |= 0x1; 
	TIM1->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_11){

	TIM1->CCR4 = timPulse;  
	TIM1->EGR |= 0x1; 
	TIM1->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_15){

	TIM2->CCR1 = timPulse;  
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_0){

	TIM3->CCR3 = timPulse;  
	TIM3->EGR |= 0x1; 
	TIM3->CR1 |=0x1;	
}  
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_1){

	TIM2->CCR4 = timPulse;  
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |=0x1;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_3){

	TIM2->CCR2 = timPulse;  
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_4){

	TIM3->CCR1 = timPulse; 
	TIM3->EGR |= 0x1; 
	TIM3->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_5){

	TIM3->CCR2 = timPulse; 
	TIM3->EGR |= 0x1; 
	TIM3->CR1 |=0x1;	
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_10){

	TIM2->CCR3 = timPulse; 
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |=0x1;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_11){

	TIM2->CCR4 = timPulse; 
	TIM2->EGR |= 0x1; 
	TIM2->CR1 |=0x1;	
}
}

void MotorConfig(Motor Port_Pin){		// DC Motor configuration including pwm settings
	
if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_0){		// GPIO and timer configurations
	
	RCC->APB1ENR |= 0x1;		  // Timer settings
	RCC->APB2ENR |= 0x5; 			// GPIO settings
	GPIOA->CRL &= 0xFFFFFFF0; // Relevant bits have set to 0
	GPIOA->CRL |= 0xB;				// Output mode and speed settings
	TIM2->CCER |= 0x1;				// Capture/ compare output configuration
	TIM2->CR1 |= 0x80;				// Auto preload enable
	TIM2->CCMR1 |= 0x68;			// Output compare and pwm mode configurations 
	TIM2->ARR = 2399; 				// Period = 2400
	TIM2->PSC = 10;						// Prescaler = 10
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_1){

	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0xB<<4);
	TIM2->CCER |= 0x10;      
	TIM2->CR1 |= 0x80;       
	TIM2->CCMR1 |= 0x6800;   
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_2){
	
	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRL &= 0xFFFFF0FF;
	GPIOA->CRL |= (0xB<<8);
	TIM2->CCER |= 0x100;
	TIM2->CR1 |= 0x80;
	TIM2->CCMR2 |= 0x68;
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_3){

	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0xB<<12);
	TIM2->CCER |= 0x1000;      
	TIM2->CR1 |= 0x80;       
	TIM2->CCMR2 |= 0x6800; 
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_6){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRL &= 0xF0FFFFFF;
	GPIOA->CRL |= (0xB<<24);
	TIM3->CCER |= 0x1;
	TIM3->CR1 |= 0x80;
	TIM3->CCMR1 |= 0x68;
	TIM3->ARR = 2399; 
	TIM3->PSC= 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_7){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (0xB<<28);
	TIM3->CCER |= 0x10;      
	TIM3->CR1 |= 0x80;       
	TIM3->CCMR1 |= 0x6800; 
	TIM3->ARR = 2399; 	
	TIM3->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<11);
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= 0xB;
	TIM1->CCER |= 0x1;
	TIM1->CR1 |= 0x80;
	TIM1->CCMR1 |= 0x68; 
	TIM1->ARR = 2399; 
	TIM1->PSC = 10;	
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<11);
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= (0xB<<4);
	TIM1->CCER |= 0x10;      
	TIM1->CR1 |= 0x80;       
	TIM1->CCMR1 |= 0x6800;  
	TIM1->ARR = 2399; 
	TIM1->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<11);
	RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= (0xB<<8);
	TIM1->CCER |= 0x100;
	TIM1->CR1 |= 0x80;
	TIM1->CCMR2 |= 0x68;
	TIM1->ARR = 2399; 
	TIM1->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<11);
	RCC->APB2ENR |= 0x5; 
	GPIOA->CRH &= 0xFFFF0FFF;
	GPIOA->CRH |= (0xB<<12);
	TIM1->CCER |= 0x1000;      
	TIM1->CR1 |= 0x80;       
	TIM1->CCMR2 |= 0x6800;  
	TIM1->ARR = 2399; 
	TIM1->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_15){

	RCC->APB2ENR |= 0x5;
	RCC->APB1ENR |= 0x1;
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= (0xB<<28);
	TIM2->CCER |= 0x1;
	TIM2->CR1 |= 0x80;
	TIM2->CCMR1 |= 0x68;
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_0){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x9; 
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOB->CRL |= 0xB;
	TIM3->CCER |= 0x100;
	TIM3->CR1 |= 0x80;
	TIM3->CCMR2 |= 0x68;
	TIM3->ARR = 2399; 
	TIM3->PSC = 10;	
}  
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_1){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x9;
	GPIOB->CRL &= 0xFFFFFF0F;
	GPIOB->CRL |= (0xB<<4);
	TIM3->CCER |= 0x1000;      
	TIM3->CR1 |= 0x80;       
	TIM3->CCMR2 |= 0x6800; 
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_3){

	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x9; 
	GPIOB->CRL &= 0xFFFF0FFF;
	GPIOB->CRL |= (0xB<<12);
	TIM2->CCER |= 0x10;      
	TIM2->CR1 |= 0x80;       
	TIM2->CCMR1 |= 0x6800; 
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_4){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x9; 
	GPIOB->CRL &= 0xFFF0FFFF;
	GPIOB->CRL |= (0xB<<16);
	TIM3->CCER |= 0x1;
	TIM3->CR1 |= 0x80;
	TIM3->CCMR1 |= 0x68;
	TIM3->ARR = 2399; 
	TIM3->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_5){

	RCC->APB1ENR |= (0x1<<1);
	RCC->APB2ENR |= 0x9;
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOB->CRL |= (0xB<<20);
	TIM3->CCER |= 0x10;      
	TIM3->CR1 |= 0x80;       
	TIM3->CCMR1 |= 0x6800;   
	TIM3->ARR = 2399; 
	TIM3->PSC = 10;	
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_10){

	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x9; 
	GPIOB->CRH &= 0xFFFFF0FF;
	GPIOB->CRH |= (0xB<<8);
	TIM2->CCER |= 0x100;
	TIM2->CR1 |= 0x80;
	TIM2->CCMR2 |= 0x68;
	TIM2->ARR= 2399; 
	TIM2->PSC = 10;
}
else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_11){

	RCC->APB1ENR |= 0x1;
	RCC->APB2ENR |= 0x9;
	GPIOB->CRH &= 0xFFFF0FFF;
	GPIOB->CRH |= (0xB<<12);
	TIM2->CCER |= 0x1000;      
	TIM2->CR1 |= 0x80;       
	TIM2->CCMR2 |= 0x6800;
	TIM2->ARR = 2399; 
	TIM2->PSC = 10;
}

// forward pin
	
if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_0){ // direction settings for forward pin
	
	RCC->APB2ENR |= (0x1<<2);		// GPIO settings
	GPIOA->CRL &= 0xFFFFFFF0;		// Relevant bits have set to 0
	GPIOA->CRL |= (0x3) ;				// Output mode and speed settings
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_2){
	
	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFF0FF;
	GPIOA->CRL |= (0x300) ;
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFF0FFFF;
	GPIOA->CRL |= (0x30000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFF0FFFFF;
	GPIOA->CRL |= (0x300000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xF0FFFFFF;
	GPIOA->CRL |= (0x3000000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (0x30000000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= (0x3);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= (0x30);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= (0x300);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFF0FFF;
	GPIOA->CRH |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_12){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xFFF0FFFF;
	GPIOA->CRH |= (0x30000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_13){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFF0FFFFF;
	GPIOA->CRH |= (0x300000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_14){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xF0FFFFFF;
	GPIOA->CRH |= (0x3000000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= (0x30000000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_0){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOB->CRL |= (0x3) ;

}  
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRL &= 0xFFFFFF0F;
	GPIOB->CRL |= (0x30);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_2){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRL &= 0xFFFFF0FF;
	GPIOB->CRL |= (0x300);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFF0FFF;
	GPIOB->CRL |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFF0FFFF;
	GPIOB->CRL |= (0x30000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOB->CRL |= (0x300000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xF0FFFFFF;
	GPIOB->CRL |= (0x3000000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRL &= 0x0FFFFFFF;
	GPIOB->CRL |= (0x30000000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFFFF0;
	GPIOB->CRH |= (0x3);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFFF0F;
	GPIOB->CRH |= (0x30);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRH &= 0xFFFFF0FF;
	GPIOB->CRH |= (0x300);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFF0FFF;
	GPIOB->CRH |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_12){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRH &= 0xFFF0FFFF;
	GPIOB->CRH |= (0x30000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_13){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRH &= 0xFF0FFFFF;
	GPIOB->CRH |= (0x300000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_14){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xF0FFFFFF;
	GPIOB->CRH |= (0x3000000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0x0FFFFFFF;
	GPIOB->CRH |= (0x30000000);
}
	
	// backward pin
	
if(Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_0){		// direction settings for forward pin
	
	RCC->APB2ENR |= (0x1<<2); 	// GPIO settings
	GPIOA->CRL &= 0xFFFFFFF0;		// Relevant bits have set to 0
	GPIOA->CRL |= (0x3);				// Output mode and speed settings
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_2){
	
	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFF0FF;
	GPIOA->CRL |= (0x300);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFF0FFFF;
	GPIOA->CRL |= (0x30000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFF0FFFFF;
	GPIOA->CRL |= (0x300000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xF0FFFFFF;
	GPIOA->CRL |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (0x30000000);	
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= (0x3);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= (0x30);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= (0x300);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFF0FFF;
	GPIOA->CRH |= (0x3000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_12){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0xFFF0FFFF;
	GPIOA->CRH |= (0x30000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_13){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFF0FFFFF;
	GPIOA->CRH |= (0x300000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_14){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xF0FFFFFF;
	GPIOA->CRH |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<2);	
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= (0x30000000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_0){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOB->CRL |= (0x3);
} 
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFF0F;
	GPIOB->CRL |= (0x30);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_2){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRL &= 0xFFFFF0FF;
	GPIOB->CRL |= (0x300);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFF0FFF;
	GPIOB->CRL |= (0x3000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFF0FFFF;
	GPIOB->CRL |= (0x30000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOB->CRL |= (0x300000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xF0FFFFFF;
	GPIOB->CRL |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0x0FFFFFFF;
	GPIOB->CRL |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFFFF0;
	GPIOB->CRH |= (0x3);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFFF0F;
	GPIOB->CRH |= (0x30);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFF0FF;
	GPIOB->CRH |= (0x300);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFF0FFF;
	GPIOB->CRH |= (0x3000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_12){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFF0FFFF;
	GPIOB->CRH |= (0x30000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_13){

	RCC->APB2ENR |= (0x1<<3);	
	GPIOB->CRH &= 0xFF0FFFFF;
	GPIOB->CRH |= (0x300000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_14){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xF0FFFFFF;
	GPIOB->CRH |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0x0FFFFFFF;
	GPIOB->CRH |= (0x30000000);
}
} 
void Basic_MotorConfig(Motor Port_Pin){		// DC Motor configuration without pwm settings

	// forward port_pin
	
if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_0){
	
	RCC->APB2ENR |= (0x1<<2);		// Relevant bits have set to 0
	GPIOA->CRL &= 0xFFFFFFF0;		// GPIO settings
	GPIOA->CRL |= (0x3);				// Output mode and speed settings
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30) ;
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_2){
	
	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFF0FF;
	GPIOA->CRL |= (0x300) ;
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xF0FFFFFF;
	GPIOA->CRL |= (0x3000000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (0x30000000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= (0x3);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= (0x30);		
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= (0x300);	
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFF0FFF;
	GPIOA->CRH |= (0x3000);
}
else if (Port_Pin.forward_port == GPIOA && Port_Pin.forward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= (0x30000000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_0){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOA->CRL |= (0x3) ;
}  
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30) ;
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000) ;
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFF0FFFF;
	GPIOA->CRL |= (0x30000) ;
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOA->CRL |= (0x300000);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFF0FF;
	GPIOB->CRH |= (0x300);
}
else if (Port_Pin.forward_port == GPIOB && Port_Pin.forward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFF0FFF;
	GPIOB->CRH |= (0x3000);
}

	// backward port_pin

if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_0){
	
	RCC->APB2ENR |= (0x1<<2); 	// GPIO settings
	GPIOA->CRL &= 0xFFFFFFF0;		// Relevant bits have set to 0
	GPIOA->CRL |= (0x3);				// Output mode and speed settings
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30);
}

else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_2){
	
	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFFF0FF;
	GPIOA->CRL |= (0x300) ;
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000);

}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_6){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0xF0FFFFFF;
	GPIOA->CRL |= (0x3000000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_7){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRL &= 0x0FFFFFFF;
	GPIOA->CRL |= (0x30000000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_8){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= (0x3);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_9){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= (0x30);	
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= (0x300);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0xFFFF0FFF;
	GPIOA->CRH |= (0x3000);
}
else if (Port_Pin.backward_port == GPIOA && Port_Pin.backward_pin == GPIO_Pin_15){

	RCC->APB2ENR |= (0x1<<2);
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= (0x30000000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_0){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFFF0;
	GPIOA->CRL |= (0x3) ;
}  
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_1){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFFFF0F;
	GPIOA->CRL |= (0x30) ;
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_3){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFFF0FFF;
	GPIOA->CRL |= (0x3000) ;
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_4){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFFF0FFFF;
	GPIOA->CRL |= (0x30000) ;
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_5){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOA->CRL |= (0x300000);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_10){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFFF0FF;
	GPIOB->CRH |= (0x300);
}
else if (Port_Pin.backward_port == GPIOB && Port_Pin.backward_pin == GPIO_Pin_11){

	RCC->APB2ENR |= (0x1<<3);
	GPIOB->CRH &= 0xFFFF0FFF;
	GPIOB->CRH |= (0x3000);
}
}

void Basic_MotorRun(Motor Port_Pin,char direction){		// Running function without pwm, just for full speed of backward or forward

	// motor direction 
	if(direction=='f'){
	
	Port_Pin.forward_port->BSRR = Port_Pin.forward_pin;		// high voltage for forward pin
	Port_Pin.backward_port->BRR = Port_Pin.backward_pin;		// low voltage for backward pin
	}
	else if(direction=='b'){
	
	Port_Pin.backward_port->BSRR = Port_Pin.backward_pin;	// high voltage for backward pin
	Port_Pin.forward_port->BRR = Port_Pin.forward_pin;		// low voltage for forward pin
	}
}
void Motor_Stop(Motor Port_Pin){		// Stop function for selected motor
	
	Port_Pin.forward_port->BRR = Port_Pin.forward_pin;		// low voltage for backward pin
	Port_Pin.backward_port->BRR = Port_Pin.backward_pin;		// low voltage for forward pin
}
