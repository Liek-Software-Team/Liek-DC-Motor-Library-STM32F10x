/**********************************************************
@author: LIEK TEAM
@version: 2.3
@date: 27.04.2021

************************************************************/

#include "stm32f10x.h" // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO


typedef struct MotorStruct{
	
 GPIO_TypeDef* pwm_port;
 uint16_t 		 pwm_pin;
	
 GPIO_TypeDef* forward_port;
 uint16_t 		 forward_pin;
	
 GPIO_TypeDef* backward_port;
 uint16_t 		 backward_pin;
	
 GPIO_TypeDef*   port;
 uint16_t				 pin;

}Motor;

void Motor_Conf(Motor Port_Pin, uint16_t speed, char direction);
void Motor_Delay(uint32_t time);
void basic_motorConf(Motor Port_Pin);
void basic_motorRun(Motor Port_Pin,char direction);
	void Motor_Stop(Motor Port_Pin);