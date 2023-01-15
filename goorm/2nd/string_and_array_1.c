// [2-1] 문자열과 배열(1)

// 예제1
#include <stdio.h>
int main(){
  char alpha[6] = { 'H', 'E', 'L', 'L', 'O', '!'};
	// char str = "Hello" 도 가능하다 
	// 배열에 null문자를 저장해야 하므로 문자열길이 +1로 선언 
	// 대문자 A 아스키코드 : 65
	// fgets : 공백을 포함한 문자열을 입력받는 함수 
	// fgets(문자배열명, 배열의크기, stdin)
  char c;
  int i;
  printf("찾고 싶은 문자 : ");
 	scanf("%c", &c);
	for(i=0; alpha[i]!='\0'; i++) { // alpha[i]에 값이 없을 때 까지 돌아가는 for문
		if(alpha[i]==c) {
			printf("%d번째\n", i+1); 
			break;
		}
	}
	return 0;
}