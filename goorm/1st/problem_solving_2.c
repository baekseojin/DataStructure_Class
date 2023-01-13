// [문제해결 01-02] 배열 기본 입출력

//5개 문자형 원소를 입력 받아 역순으로 출력해보자.
//순서대로 출력한 다음 수정하여 작성해 보자.
#include <stdio.h>

int main(){
  char arr[5];
	for(int i=0; i<5; i++) {
		scanf("%c", &arr[i]);
		getchar(); // 입력받은  문자열을 공백 제거하고 저장한다.
		/*
		(1) getchar() 가 실행되면 문자열 or 문자를 입력 받는다.
		(2) 문자열 or 문자을 바로 char ch; 에 저장되는 것이 아니라 입력버퍼에 저장된다.
		(3) getchar()의 반환값으로 입력버퍼에서 문자 한 개를 꺼내서 ch에 저장한다. */
	}
	for(int i=4; i>=0; i--) {
		printf("%c", arr[i]);
	}
    return 0;
}