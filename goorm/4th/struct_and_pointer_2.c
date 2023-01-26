// [4-1] 구조체와 포인터(2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 포인터에는 malloc 함수를 사용하여 동적 메모리를 할당 가능 
// 포인터는 8byte , 구조체 포인터도 8byte

//멤버의 주소값을 가지고 
typedef struct {
	char name[20];
	int* p;
} data;

int main() {
	int n=50;
	data d1;
	data *d2 = (data*)malloc(sizeof(data)); // sizeof(data) = 9(char(1) + int*(8))
	d1.p = &n;
	d2->p = &n;
	printf("%d\n", *d1.p + *d2->p);
	strcpy(d2->name, "bobby");
	printf("%s\n", (*d2).name);
	printf("%d\n", *(*d2).p);
	
	free(d2);
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
// 구조체 역참조 중간고사 꼭 나옴!!!!!!(7번)
typedef struct {
	char c1;
	int *numPtr;    // 포인터
} Data;
int main()
{
	int num1 = 10;
	Data d1;    // 구조체 변수
	Data *d2 = (Data*)malloc(sizeof(Data));    // 구조체 포인터에 메모리 할당
	d1.numPtr = &num1;
	d2->numPtr = &num1;
	printf("%d\n", *d1.numPtr);     // 10: 구조체의 멤버를 역참조
	printf("%d\n", *d2->numPtr);    // 10: 구조체 포인터의 멤버를 역참조

	d2->c1 = 'a';
	printf("%c\n", (*d2).c1);      //  a: 구조체 포인터를 역참조하여 c1에 접근
	// d2->c1과 같음
	printf("%d\n", *(*d2).numPtr); // 10: 구조체 포인터를 역참조하여 numPtr에 접근한 뒤 다시 역참조
	// *d2->numPtr과 같음

	free(d2);

	return 0;
}
*/