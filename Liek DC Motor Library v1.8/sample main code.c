/**********************************************************
@author: LIEK TEAM
@version: 1.8
@date: 03.04.2021
************************************************************/

#include "stm32f10x.h"                  // Device header
#include "dc_motor_library.h"

Motor Motor1;
	
int main(){
	
	Motor1.backward_port=GPIOA;
	Motor1.backward_pin= GPIO_Pin_1;
	
	Motor1.forward_port=GPIOA;
	Motor1.forward_pin=GPIO_Pin_2;
	
	Motor1.pwm_pin=GPIO_Pin_3;
	Motor1.pwm_port=GPIOA;
	
  Motor_Conf(Motor1);
 
	while(1){
		
		Pwm_MotorRun(Motor1,90,'f');
		
		Motor_Delay(3000);
		
		Motor_Stop(Motor1);
		Motor_Delay(500);
		
		Pwm_MotorRun(Motor1,70,'b');
		Motor_Delay(3000);
		
		Motor_Stop(Motor1);
		Motor_Delay(500);
	}
}
