/**********************************************************
@author: LIEK TEAM
@version: 2.3
@date: 27.04.2021
************************************************************/

#include "stm32f10x.h"                  // Device header
#include "dc_motor_library.h"

Motor Motor1;

int main(){
	
	Motor1.backward_port=GPIOA;
	Motor1.backward_pin= GPIO_Pin_4;
	
	Motor1.forward_port=GPIOA;
	Motor1.forward_pin=GPIO_Pin_5;

	basic_motorConf(Motor1);
	
	while(1){
	
		basic_motorRun(Motor1,'b');
		Motor_Delay(3000);
		
		Motor_Stop(Motor1);
		Motor_Delay(500);
		
		basic_motorRun(Motor1,'f');
		Motor_Delay(3000);
	}
}
