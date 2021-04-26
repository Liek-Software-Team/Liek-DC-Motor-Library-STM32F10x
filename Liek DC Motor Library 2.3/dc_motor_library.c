/**********************************************************
@author: LIEK TEAM
@version: 2.3
@date: 27.04.2021
************************************************************/

#include "stm32f10x.h"                  // Device header
#include  "dc_motor_library.h"
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

GPIO_InitTypeDef MotorGPIOInitStructure;

int counter = 0;

void systemClockEnable(void){
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock/1000);
}

void SysTick_Handler(void){
    if(counter>0){
        counter--;
    }
}

void Motor_Delay(uint32_t time){
        systemClockEnable();
    counter=time;
    while(counter);
}

void Motor_Conf(Motor Port_Pin, uint16_t speed, char direction){
	
	 uint16_t timPulse = 	24*speed;

if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_0){
	
	
	RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xFFFFFFF0;
		GPIOA->CRL |= 0xB;
		TIM2->CCER |= 0x1;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR1 |= 0x68;
TIM2->ARR = 2399; 
TIM2->PSC = 10;
TIM2->CCR1 = timPulse;  
TIM2->EGR |= 0x1; 
TIM2->CR1 |= 0x1;
	

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
TIM2->CCR2= timPulse;  
TIM2->EGR |= 0x1; 
TIM2->CR1 |= 0x1;
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
TIM2->CCR3 = timPulse;  
TIM2->EGR |= 0x1;
TIM2->CR1 |= 0x1;	
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
	TIM2->CCR4 = timPulse;  
	TIM2->EGR |= 0x1;
	TIM2->CR1 |= 0x1;

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
TIM3->CCR1 = timPulse;  
TIM3->EGR |= 0x1; 
TIM3->CR1 |=0x1;
	

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
TIM3->CCR2 = timPulse;  
TIM3->EGR |= 0x1; 
TIM3->CR1 |=0x1;	

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
TIM1->CCR1 = timPulse;  
TIM1->EGR |= 0x1; 
TIM1->CR1 |=0x1;
	

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
TIM1->CCR2 = timPulse;  
TIM1->EGR |= 0x1; 
TIM1->CR1 |=0x1;
	
		
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
TIM1->CCR3 = timPulse;  
TIM1->EGR |= 0x1; 
TIM1->CR1 |=0x1;
	
		
}

else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_11){

RCC->APB2ENR |= (0x1<<11);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRH &= 0xFFFF0FFF;
		GPIOA->CRH |= (0xB<<12);
		TIM1->CCER |= 0x1000;      
		TIM1->CR1 |= 0x80;       
		TIM1->CCMR2 |= 0x6800;  
TIM1->ARR = 2399; 
TIM1->PSC = 10;
TIM1->CCR4 = timPulse;  
TIM1->EGR |= 0x1; 
TIM1->CR1 |=0x1;	
	
}

else if (Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_15){

RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		RCC->APB1ENR |= 0x1;
		GPIOA->CRH &= 0x0FFFFFFF;
		GPIOA->CRH |= (0xB<<28);
		TIM2->CCER |= 0x1;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR1 |= 0x68;
TIM2->ARR = 2399; 
TIM2->PSC = 10;
TIM2->CCR1 = timPulse;  
TIM2->EGR |= 0x1; 
TIM2->CR1 |=0x1;	
	
		

}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_0){

RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFFFFF0;
		GPIOB->CRL |= 0xB;
		TIM3->CCER |= 0x100;
		TIM3->CR1 |= 0x80;
		TIM3->CCMR2 |= 0x68;
TIM3->ARR = 2399; 
TIM3->PSC = 10;
TIM3->CCR3 = timPulse;  
TIM3->EGR |= 0x1; 
TIM3->CR1 |=0x1;	
	
		

}  

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_1){

RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFFFF0F;
		GPIOB->CRL |= (0xB<<4);
		TIM3->CCER |= 0x1000;      
		TIM3->CR1 |= 0x80;       
		TIM3->CCMR2 |= 0x6800; 
TIM2->ARR = 2399; 
TIM2->PSC = 10;
TIM2->CCR4 = timPulse;  
TIM2->EGR |= 0x1; 
TIM2->CR1 |=0x1;

	

}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_3){

RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFF0FFF;
		GPIOB->CRL |= (0xB<<12);
		TIM2->CCER |= 0x10;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR1 |= 0x6800; 
TIM2->ARR = 2399; 
TIM2->PSC = 10;
TIM2->CCR2 = timPulse;  
TIM2->EGR |= 0x1; ;
TIM2->CR1 |=0x1;	
	
		

}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_4){

RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFF0FFFF;
		GPIOB->CRL |= (0xB<<16);
		TIM3->CCER |= 0x1;
		TIM3->CR1 |= 0x80;
		TIM3->CCMR1 |= 0x68;
TIM3->ARR = 2399; 
TIM3->PSC = 10;
TIM3->CCR1 = timPulse; 
TIM3->EGR |= 0x1; 
TIM3->CR1 |=0x1;	
	
		

}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_5){

RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFF0FFFFF;
		GPIOB->CRL |= (0xB<<20);
		TIM3->CCER |= 0x10;      
		TIM3->CR1 |= 0x80;       
		TIM3->CCMR1 |= 0x6800;   
TIM3->ARR = 2399; 
TIM3->PSC = 10;
TIM3->CCR2 = timPulse; 
TIM3->EGR |= 0x1; 
TIM3->CR1 |=0x1;	
	
		

}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_10){

RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRH &= 0xFFFFF0FF;
		GPIOB->CRH |= (0xB<<8);
		TIM2->CCER |= 0x100;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR2 |= 0x68;
TIM2->ARR= 2399; 
TIM2->PSC = 10;
TIM2->CR1 |= 0x80;
TIM2->CCR3 = timPulse; 
TIM2->EGR |= 0x1; 
TIM2->CR1 |=0x1;	
}

else if (Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_11){

RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRH &= 0xFFFF0FFF;
		GPIOB->CRH |= (0xB<<12);
		TIM2->CCER |= 0x1000;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR2 |= 0x6800;
TIM2->ARR = 2399; 
TIM2->PSC = 10;
TIM2->CCR4 = timPulse; 
TIM2->EGR |= 0x1; 
TIM2->CR1 |=0x1;	
}

    // forward pin

	if(Port_Pin.forward_port == GPIOA)
	{
		RCC->APB2ENR |= (0x1<<2);  
	}else if(Port_Pin.forward_port == GPIOB)
	{
	 RCC->APB2ENR |= (0x1<<3);  
	
	}else if(Port_Pin.forward_port == GPIOC)
	{
	RCC->APB2ENR |= (0x1<<4);  
		
	}else if(Port_Pin.forward_port == GPIOD)
	{
	RCC->APB2ENR |= (0x1<<5);  
	}else if(Port_Pin.forward_port == GPIOE)
	{
	 RCC->APB2ENR |= (0x1<<6);  
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.forward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.forward_port,&MotorGPIOInitStructure);
	
	
	// backward pin
	
	if(Port_Pin.backward_port == GPIOA)
	{
		RCC->APB2ENR |= (0x1<<2);  
		
	}else if(Port_Pin.backward_port == GPIOB)
	{
	RCC->APB2ENR |= (0x1<<3);  
	
	}else if(Port_Pin.backward_port == GPIOC)
	{
	RCC->APB2ENR |= (0x1<<4);  
		
	}else if(Port_Pin.backward_port == GPIOD)
	{
		
	RCC->APB2ENR |= (0x1<<5);  
		
	}else if(Port_Pin.backward_port == GPIOE)
	{
		
	RCC->APB2ENR |= (0x1<<6);  
	}
	
	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.backward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.backward_port,&MotorGPIOInitStructure);
	

	
	// motor direction 
	if(direction=='f'){
	
	GPIO_SetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_ResetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 
	}

	else if(direction=='b'){
	
	GPIO_ResetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_SetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 

	
}
	



} 

void basic_motorConf(Motor Port_Pin){

// forward port_pin
	
	if(Port_Pin.forward_port == GPIOA)
	{
		RCC->APB2ENR |= (0x1<<2);  
	}else if(Port_Pin.forward_port == GPIOB)
	{
	RCC->APB2ENR |= (0x1<<3);  
	
	}else if(Port_Pin.forward_port == GPIOC)
	{
	RCC->APB2ENR |= (0x1<<4);  
		
	}else if(Port_Pin.forward_port == GPIOD)
	{
	RCC->APB2ENR |= (0x1<<5);  
	
	}else if(Port_Pin.forward_port == GPIOE)
	{
		
	RCC->APB2ENR |= (0x1<<6);  
	}
                                                                      
	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.forward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.forward_port,&MotorGPIOInitStructure);
	
	
	// backward port_pin
	
	if(Port_Pin.backward_port == GPIOA)
	{
		RCC->APB2ENR |= (0x1<<2);  
	}else if(Port_Pin.backward_port == GPIOB)
	{
	RCC->APB2ENR |= (0x1<<3);  
	
	}else if(Port_Pin.backward_port == GPIOC)
	{
	RCC->APB2ENR |= (0x1<<4);  
		
	}else if(Port_Pin.backward_port == GPIOD)
	{
		
	RCC->APB2ENR |= (0x1<<5);  
		
	}else if(Port_Pin.backward_port == GPIOE)
	{
	RCC->APB2ENR |= (0x1<<6);
		
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.backward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.backward_port,&MotorGPIOInitStructure);
	

}


void basic_motorRun(Motor Port_Pin,char direction){

// motor direction 
	if(direction=='f'){
	
	GPIO_SetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_ResetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 
	}

	else if(direction=='b'){
	
	GPIO_ResetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_SetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 
	}


}
void Motor_Stop(Motor Port_Pin){

	GPIO_ResetBits(Port_Pin.backward_port,Port_Pin.backward_pin);
	GPIO_ResetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
}
