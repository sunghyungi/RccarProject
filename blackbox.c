#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<time.h>

#define VIV 3
#define BUZZER 23

char* timeToString(struct tm *t);

int main() {

	if (wiringPiSetup() == -1)
		return 1;
	pinMode(VIV, INPUT);		//진동감지센서 INPUT
	pinMode(BUZZER, OUTPUT);	//부저 OUTPUT

	struct tm *t;
	time_t timer;

	//printf("%s\n", timeToString(t));

	while (1) {
		int a = digitalRead(VIV);	// a == 0 진동o, a == 1 진동x

		printf("%d\n", a);
		digitalWrite(BUZZER, 0);		// 평소에는 BUZZER을 LOW시켜서 소리가 안남
		if (a == 0) {				// 진동이 울리면

			digitalWrite(BUZZER, 1);		// HIGH시켜서 소리가 나게 함

			timer = time(NULL);    // 현재 시각을 초 단위로 얻기
			t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
			char bash[40];
			sprintf(bash, "%s %s", "sh black.sh", timeToString(t));
			printf("%s\n",timeToString(t));
			printf("%s\n", bash);
			system(bash);		// 카메라촬영하는 쉘 스크립트 실행.
			delay(100);
		}
		delay(10);
	}
}

char* timeToString(struct tm *t) {
	static char s[20];

	sprintf(s, "%04d-%02d-%02d %02d-%02d-%02d", t->tm_year + 1900,
			t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

	return s;
}

