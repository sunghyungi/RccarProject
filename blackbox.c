#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>

#define VIV 15
#define BUZZER 23

int main(){
	if (wiringPiSetup() == -1)
	    	return 1;
	pinMode(VIV,INPUT);		//진동감지센서 INPUT
	pinMode(BUZZER, OUTPUT);	//부저 OUTPUT

	while(1){
		int a = digitalRead(VIV);	// a == 0 진동o, a == 1 진동x

		printf("%d\n",a);
		digitalWrite(BUZZER,0);			// 평소에는 BUZZER을 LOW시켜서 소리가 안남
		if(a==0){				// 진동이 울리면 
			digitalWrite(BUZZER,1);		// HIGH시켜서 소리가 나게 함
			system("sh black.sh 1");	// 카메라촬영하는 쉘 스크립트 실행.
		delay(100);
		}
		delay(100);
	}
}

