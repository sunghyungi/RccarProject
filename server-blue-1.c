#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>

#define viv 15
#define ALARM 23

int main(){
	if (wiringPiSetup() == -1)
	    	return 1;
	pinMode(viv,INPUT);

	while(1){
		int a = digitalRead(viv);

		printf("%d\n",a);
		digitalWrite(ALARM,0);
		if(a==0){
			digitalWrite(ALARM,1);
			system("sh black.sh 1");
		delay(100);
		}
		delay(100);
	}
}

