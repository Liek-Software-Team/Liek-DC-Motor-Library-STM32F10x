/**********************************************************
@author: LIEK TEAM
@version: 1.8
@date: 03.04.2021
************************************************************/

#include "stm32f10x.h"                  // Device header
#include  "dc_motor_library.h"
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

GPIO_InitTypeDef  MotorGPIOInitStructure;
TIM_OCInitTypeDef TIMER_OCInitStructure;
TIM_TimeBaseInitTypeDef TIMERInitstructure;

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

void timer_configure(uint16_t TIM){
	
  if(TIM ==1){
	 
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
		
		TIMERInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIMERInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
		TIMERInitstructure.TIM_Period=2399;
		TIMERInitstructure.TIM_Prescaler=10;
		TIMERInitstructure.TIM_RepetitionCounter=0;
		
		TIM_TimeBaseInit(TIM1,&TIMERInitstructure);
		TIM_Cmd(TIM1,ENABLE);
	}
	if(TIM ==2){
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
		
		TIMERInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIMERInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
		TIMERInitstructure.TIM_Period=2399;
		TIMERInitstructure.TIM_Prescaler=10;
		TIMERInitstructure.TIM_RepetitionCounter=0;
		
		TIM_TimeBaseInit(TIM2,&TIMERInitstructure);
		TIM_Cmd(TIM2,ENABLE);
	}
	if(TIM ==3){
		
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
		
		TIMERInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIMERInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
		TIMERInitstructure.TIM_Period=2399;
		TIMERInitstructure.TIM_Prescaler=10;
		TIMERInitstructure.TIM_RepetitionCounter=0;
		
		TIM_TimeBaseInit(TIM3,&TIMERInitstructure);
		TIM_Cmd(TIM3,ENABLE);
	}
	if(TIM ==4){
		
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
		
		TIMERInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIMERInitstructure.TIM_CounterMode=TIM_CounterMode_Up;	
		TIMERInitstructure.TIM_Period=2399;
		TIMERInitstructure.TIM_Prescaler=10;
		TIMERInitstructure.TIM_RepetitionCounter=0;
		
		TIM_TimeBaseInit(TIM4,&TIMERInitstructure);
		TIM_Cmd(TIM4,ENABLE);
	}
}

void Motor_Conf(Motor Port_Pin){
	
	// pwm port
	if(Port_Pin.pwm_port == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}else if(Port_Pin.pwm_port == GPIOB)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	}else if(Port_Pin.pwm_port == GPIOC)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
	}else if(Port_Pin.pwm_port == GPIOD)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	}else if(Port_Pin.pwm_port == GPIOE)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	}
	
	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.pwm_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.pwm_port,&MotorGPIOInitStructure);
	
	// pwm pin

  if (Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_0)     {timer_configure(2);}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_1) {timer_configure(2);}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_2) {timer_configure(2);}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_3) {timer_configure(2);}	
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_6) {timer_configure(3);}		
	else if(Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_7) {timer_configure(3);}			
	else if(Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_8) {timer_configure(1);}				
	else if(Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_9) {timer_configure(1);}			
	else if(Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_10){timer_configure(1);}			
	else if(Port_Pin.pwm_port== GPIOA && Port_Pin.pwm_pin == GPIO_Pin_11){timer_configure(1);}			
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_15){timer_configure(2);}		
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_0) {timer_configure(3);}			
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_1) {timer_configure(2);}		
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_3) {timer_configure(2);}		
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_4) {timer_configure(3);}			
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_5) {timer_configure(3);}		
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_10){timer_configure(2);}		
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_11){timer_configure(2);}	
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_13){timer_configure(1);}			
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_14){timer_configure(1);}			
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_15){timer_configure(1);}			

	// forward pin
	
	if(Port_Pin.forward_port == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}else if(Port_Pin.forward_port == GPIOB)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	}else if(Port_Pin.forward_port == GPIOC)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
	}else if(Port_Pin.forward_port == GPIOD)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	}else if(Port_Pin.forward_port == GPIOE)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.forward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.forward_port,&MotorGPIOInitStructure);
	
	// backward pin
	
	if(Port_Pin.backward_port == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}else if(Port_Pin.backward_port == GPIOB)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	}else if(Port_Pin.backward_port == GPIOC)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
	}else if(Port_Pin.backward_port == GPIOD)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	}else if(Port_Pin.backward_port == GPIOE)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.backward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.backward_port,&MotorGPIOInitStructure);
}

void Pwm_MotorRun(Motor Port_Pin,uint16_t speed, char direction){
 uint16_t timPulse = 	24*speed;

	// motor direction 
	if(direction=='f'){
	
	GPIO_SetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_ResetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 
	}

	else if(direction=='b'){
	
	GPIO_ResetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
	GPIO_SetBits(Port_Pin.backward_port,Port_Pin.backward_pin); 
	}
	
	// motor speed 
	
	TIMER_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;  // bu ve alttaki 2 satir conf a tasinabilir
	TIMER_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIMER_OCInitStructure.TIM_OCNPolarity=TIM_OCPolarity_High;
	TIMER_OCInitStructure.TIM_Pulse=timPulse;
	
	if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin== GPIO_Pin_1){
	
	TIM_OC2Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);	
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_2){
	
	TIM_OC3Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);		
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_3){

	TIM_OC4Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);	
	} 
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_6){

	TIM_OC1Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);	
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_7){
	
	TIM_OC2Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);		
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_8){
	
	TIM_OC1Init(TIM1,&TIMER_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);		
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_9){
	
	TIM_OC2Init(TIM1,&TIMER_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_10){
	
	TIM_OC3Init(TIM1,&TIMER_OCInitStructure);
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_11){
	
	TIM_OC4Init(TIM1,&TIMER_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);
	}
	
	else if(Port_Pin.pwm_port == GPIOA && Port_Pin.pwm_pin == GPIO_Pin_15){
	
	TIM_OC1Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	}	
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_0){
	
	TIM_OC3Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_1){
	
	TIM_OC4Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_3){
	
	TIM_OC2Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_4){
	
	TIM_OC1Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_5){
	
	TIM_OC2Init(TIM3,&TIMER_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_10){
	
	TIM_OC3Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);
	}
	else if(Port_Pin.pwm_port == GPIOB && Port_Pin.pwm_pin == GPIO_Pin_11){
	
	TIM_OC4Init(TIM2,&TIMER_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	}
} 

void Motor_Stop(Motor Port_Pin){

	GPIO_ResetBits(Port_Pin.backward_port,Port_Pin.backward_pin);
	GPIO_ResetBits(Port_Pin.forward_port,Port_Pin.forward_pin);
}

void Basic_MotorConf(Motor Port_Pin){

// forward port_pin
	
	if(Port_Pin.forward_port == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}else if(Port_Pin.forward_port == GPIOB)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	}else if(Port_Pin.forward_port == GPIOC)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
	}else if(Port_Pin.forward_port == GPIOD)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	}else if(Port_Pin.forward_port == GPIOE)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.forward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.forward_port,&MotorGPIOInitStructure);
	
	// backward port_pin
	
	if(Port_Pin.backward_port == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}else if(Port_Pin.backward_port == GPIOB)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	}else if(Port_Pin.backward_port == GPIOC)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
	}else if(Port_Pin.backward_port == GPIOD)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	}else if(Port_Pin.backward_port == GPIOE)
	{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	}

	MotorGPIOInitStructure.GPIO_Pin=Port_Pin.backward_pin;
	MotorGPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	MotorGPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Port_Pin.backward_port,&MotorGPIOInitStructure);
}

void Basic_MotorRun(Motor Port_Pin,char direction){

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
