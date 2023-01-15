// [문제해결2-1] strlen 함수 구현

#include <stdio.h>

int myStrlen( char* str );
int myStrlen2( char* str );
int myStrlen3( char* str );
int myStrlen4( char* str, char a );
// 문자 변수 - '0' 
// ex) '2' - '0' 
// 응용 -> (변수 >='A' && 변수<='Z') // 65

int main() {
	char s[100];
	fgets(s, 100, stdin); // 마지막에 \n, \0 같이 저장
	
	printf("%d\n", myStrlen(s)); // 문자 길이 
	printf("%d\n", myStrlen2(s)); // 문자 중 digit의 개수 : 숫자의 개수
	// printf("%d\n", myStrlen3(s)); // 공백제외 길이 
	// printf("%d\n", myStrlen4(s, 't')); // t의 개수
	
	return 0;
}

int myStrlen( char* str ) {
	//  문자 길이 구하는 코드
	int i=0; 
	int count=0;
	for(i=0; *(str+i)!='\0'; i++) { // str[i]!='\0' == *(str+1)!='\0'
		count++;
	}
	return count-1;
}

int myStrlen2( char* str ){
	// 문자 중 digit의 개수 구하는 코드
	int count=0;
	for(int i=0; *(str+i)!='\0'; i++) {
		 if(*(str+i)>='0' && *(str+i)<='9') {
			 count++; 
		 }
	}
	return count;
}

int myStrlen3(char* str ) {
	int i = 0;
	int count = 0;
	for(int i=0; *(str+i)!='\0'; i++) {
		if(str[i]=='a') continue;
		else count++;
	}
	return count-1;
}

int myStrlen4(char* str, char a) {
	int i = 0;
	int count = 0;
	for(int i=0; *(str+i)!='\0'; i++) {
		if(*(str+i)==a) {
			count++;
		}
	}
	return count;
}