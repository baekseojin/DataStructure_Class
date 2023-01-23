// [실습과제 3-4] 엘니뇨 & 라니냐 프로젝트

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// abs는 정수 절대값, labs는 long int 형 절대값, fabs는 float, double형 절대값

int main() {
	float enso[11][2] = { {1990, 0.6}, // 엘니뇨
											  {1991, 0.2}, // 엘니뇨
												{1992, 1.1}, // 엘니뇨
											  {1993, 0.5}, // 엘니뇨
											  {1994, 0.1}, // 엘니뇨
											  {1995, 1.2}, // 엘니뇨
											  {1996, -0.3}, // 라니냐
											  {1997, -0.1}, // 라니냐
											  {1998, 2.2},  // 엘니뇨
											  {1999, -0.7}, // 라니냐
											  {2000, -1.1} // 라니냐
											};
	
	printf("엘니뇨 : ");
	for(int i=0; i<11; i++) {
		if(enso[i][1] > 0) {
			printf("%.f ", enso[i][0]); // .f하면 소숫점 때고 출력
		}
	}
	printf("\n");
	
	
	printf("가장 강한 엘니뇨 : ");
	float max = -100;
	for(int i=0; i<11; i++) {
		if(enso[i][1]>max) {
			max = enso[i][1];
		}
	}
	for(int i=0; i<11; i++) {
		if(max == enso[i][1]) {
			printf("%.f\n", enso[i][0]);
		}
	}
	
	
	printf("라니냐 : ");
	for(int i=0; i<11; i++) {
		if(enso[i][1] < 0) {
			printf("%.f ", enso[i][0]); // .f하면 소숫점 때고 출력
		}
	}
	printf("\n");
	
	
	printf("가장 강한 라니냐 : ");
	float min = 100;
	for(int i=0; i<11; i++) {
		if(enso[i][1]<min) {
			min = enso[i][1];
		}
	}
	for(int i=0; i<11; i++) {
		if(min == enso[i][1]) {
			printf("%.f\n", enso[i][0]);
		}
	}
	
	int year;
	printf("가장 정상적인 해 : ");
	min = 100;
	for(int i=0; i<11; i++) {
		if( (fabs(enso[i][1])) < min) {
			min = fabs(enso[i][1]); // 0.1
		}
	}
	
	for(int i=0; i<11; i++) {
		if(min == fabs(enso[i][1])) {
			year = enso[i][0];
			printf("%d ", year);
		}
	}	
	
	return 0;
}