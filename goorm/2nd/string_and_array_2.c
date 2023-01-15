// [2-2] 문자열과 배열(2)

#include <stdio.h>
#include <string.h> // strlen을 위해서 헤더파일 불러옴

int main(void) {
  char str[50];
  char c;
	int i;
	int len = 0;
	scanf("%s", str); // 배열 이름이 이미 주소라서 주소연산자를 쓰지 않음
	getchar(); // 공백을 입력받는 함수 //getchar 뒤에 변수를 안받는데 그러면 getchar 위에 입력받는 변수 모두 공백까지 입력받나요??  
	scanf("%c", &c);
	len = strlen(str);
	for(i=0; str[i]!='\0'; i++) {
		if(str[i]==c) {
			printf("%d번째\n", i+1);
			break;
		}
	}
  return 0;
}