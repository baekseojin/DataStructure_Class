// [2-3] 포인터와 문자열

#include <stdio.h>

/* 1. 문자열을 저장하는 배열과 포인터의 차이
	char* pc="mango";
	char str[80]="apple";
	pc="banana";
	strcpy(str, pc); // pc 문자열을 str 문자열에 복사, string copy 함수
	strcat(str, pc); // 문자열 붙이기, str+pc   
	str[0]='t';
 	printf("%s\n", str);
 	printf("문자형 포인터 크기 = %d %s\n", sizeof(pc), pc); 
*/


// 2. 문자열 연산함수 예제 1
size_t myStrlen(const char* str); // size_t : 부호없는 int를 재정의한 것

int main() {

	char s[]="hello"; // s는 주소
	printf("%d\n", myStrlen(s)); // null문자 빼고 5를 출력
	
	return 0;
}

size_t myStrlen(const char* str) {
	char* s;	
	for(s = str; *s!='\0'; s++) { // *s가 참이면 , 값이 0(null)이 아니면( *s!='0' == *s ) s의 시작주소부터 1씩 증가
		printf("%8X\n", s);
	}
	printf("%8X\n", s);
	printf("s = %8X, str = %8X \n", s, str); // %8X : 16진수를 8자리로 출력
	return s-str; // str은 시작주소, s는 시작주소 + 문자열의 길이, 마지막 주소 - 시작주소가 문자 길이
}