// [문제해결 2-3] 부분문자열

#include <stdio.h>
#include <stdlib.h>
 int main(){
    int a,b,i;
    char* str= (char*)malloc(sizeof(char)*100); //char str[100]의 의미
    scanf("%s",str); // abcdefg
    scanf("%d %d",&a,&b); // a=2, b=4
	 	/* 
			1. for문으로 풀기 
			for(i=a-1; i<=b-1; i++) {
		 		printf("%c", str[i]);
		 	}
		*/

	 	/* 
			2. 인덱스에 null값을 넣어서 강제로 종료 
	 	 	0 1 2 3 4 5 6 7
	 	 	a b c d e f g h
	 	 	2부터 4까지 출력 = b c d니까 e에(str[b]) null값을 넣는다. 
	 	*/
		str[b]='\0'; // 4번째 인덱스에 0을 넣는다
	 	printf("%s", str+(a-1)); // str의 첫번째 인덱스(b)부터 null값이 아닐 때까지 출력 
	 
    return 0;
}