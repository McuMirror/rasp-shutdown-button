#include <wiringPi.h>
#include <stdio.h>
#define POWER_SRC 4
#define SHUT_BUT_PIN 5
//static volatile but_hold_time = 0;
// void shut_but_interrupt(void)
// {
// 	int status = digitalRead(SHUT_BUT_PIN);
// 	if (status == 1) {//up edge
		
// 	} else { //down edge

// 	}
// }

int main(void)
{
	wiringPiSetup ();
	pinMode(POWER_SRC,OUTPUT);
	pinMode(SHUT_BUT_PIN, INPUT);
	digitalWrite(POWER_SRC, HIGH);
	int but_hold_time = 0;
//	wiringPiISR (SHUT_BUT_PIN, INT_EDGE_BOTH, &shut_but_interrupt);
	while(1){
		if(digitalRead(SHUT_BUT_PIN))
			but_hold_time++;
		else
			but_hold_time = 0;
		if(but_hold_time > 10){
			system("sudo shutdown -h now");
			return 0;
		}
		delay (500) ;
	}
	return 0;
}
