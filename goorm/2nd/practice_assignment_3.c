// [실습과제 2-3] 포인터(펠린드롬)

#include <stdio.h>
#include <string.h>
int ispalandrom(char* mystr1) {
	int len = 0, i;
	int flag = 1;
	len = strlen(mystr1)  ; //입력문자열의 길이 저장
	
	for(i=0 ; i<len/2 ; i++) { // 문자열 길이의 반보다 작으면
		if (mystr1[i]!=mystr1[len-i-1]) {// 예를 들어 level 에서 v를 기준으로 양옆 문자를 비교하여 다르면
			flag = 0;	
			return ;
		}
	}
	
	return flag ;
}

int main() {
	char mystr1[256]; 
	char mystr2[256]; 

	gets(mystr1); // apple
	if (ispalandrom(mystr1)==1) {   //펠린드롬 판정 함수 호출
		// ==1을 쓰는 것과 안쓰는 것 차이가 없을 텐데 결과가 다르게 나옴
		printf("Yes\n");
	}
	else {
		printf("No\n");
	} 
	
	return 0;
}