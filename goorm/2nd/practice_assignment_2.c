// [실습과제 2-2] 문자열(쉼표)

#include <stdio.h>
#include <string.h>
int main() {
	char str[100];
	int num, i, len, tot=0;
	
  // 문자열을 0번째부터 탐색  --1)
		  //if (문자가 ,이면) 세자리 숫자를 출력
		      //---1) 실행
		  //num값을 누적 계산
	scanf("%s", &str);
	for(i=0; str[i]!='\0'; i++) {
		if(str[i]==',') {
			printf("%d\n", num);
			num=0;
			continue;
		}
		num = num*10 + (str[i]-'0'); // 문자 0 = 아스키 코드로 48, 문자 - 문자는 숫자
	}
	
	printf("%d\n", num);
	return 0;
}