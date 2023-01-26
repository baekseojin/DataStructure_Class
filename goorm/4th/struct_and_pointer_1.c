// [4-1] 구조체와 포인터(1)

// 구조체 : 타입이 다른 데이터를 하나로 묶는 방법
// 배열 : 타입이 다른 데이터를 하나로 묶는 방법 (배열의 이름은 주소 )

// struct example s1 = int si

#include<stdio.h>
#include<string.h>
#define NUM 3

//전역에 구조체 정의
typedef struct {  
	char name[10];
	int age;
} PERSON; // person으로 정의한다 

void inputData( PERSON *p );
void outputData( PERSON *p );

int main() {
	//구조체 포인터 배열 선언
	PERSON p[3]; //  	
	inputData(p);
	outputData(p);
	//구조체포인터 배열로 입력함수 호출

	//구조체포인터 배열로 출력함수 호출

		return 0;
}

void inputData( PERSON *p ){
	//구조체포인터 변수에 입력
	int i;
	for(i=0; i<3; i++) {
		scanf("%s %d", p[i].name, &p[i].age);
	}
}

void outputData( PERSON *p ){ // PERSON *p == PERSON p[]
	//구조체포인터 변수에 출력
	int i;
	for(i=0; i<3; i++) {
		printf("%s, %d\n", p[i].name, p[i].age);
	}
} 