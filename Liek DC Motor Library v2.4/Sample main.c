/**********************************************************
@author: LIEK TEAM
@version: 2.4
@date: 01.05.2021
-PWM pins for speed control: A0,A1,...,A7 and B0. Other pwm pins does not work.
-Digital pins for direction: All GPIO pins except A15, B3, B4.
************************************************************/
#include "dc_motor_library.h"

Motor Motor1;												// The object "Motor1" has been set in the Motor structure. The object name (Motor1) depends on the user. 

int main(){
	
	Motor1.pwm_port = GPIOA;					// Port and pin assignments for pwm 
	Motor1.pwm_pin = GPIO_Pin_7;			// If pwm not used, pwm_port and pwm_pin assignments are unnecessary.
	
	Motor1.backward_port = GPIOB;			// Port and pin assignments for forward direction
	Motor1.backward_pin = GPIO_Pin_12;	// port = GPIOx & pin = GPIO_Pin_x
	
	Motor1.forward_port = GPIOA;			// Port and pin assignments for backward direction
	Motor1.forward_pin = GPIO_Pin_9;	// port = GPIOx & pin = GPIO_Pin_x

	MotorConfig(Motor1);							// DC Motor configuration including pwm settings
																		// If pwm not used, Basic_MotorConfig() function have to be used instead of MotorConfig().
	while(1){
	
		MotorRun(Motor1,100,'b');				// Running function with pwm 	// MotorRun(Motor object, speed(min:0 max:100), direction('f':forward & 'b':backward))
																		// If pwm not used, Basic_MotorRun() function have to be used instead of MotorRun().	// Basic_MotorRun(Motor object, direction('f':forward & 'b':backward))
		Motor_Delay(3000);
		
		Motor_Stop(Motor1);							// Motor_Stop(Motor object)
		Motor_Delay(800);								// Motor_Delay(time(millisecond))
		
		MotorRun(Motor1,75,'f');				// %75 speed and forward direction for Motor1
		Motor_Delay(3000);
		
		Motor_Stop(Motor1);
		Motor_Delay(800);
	}
}
