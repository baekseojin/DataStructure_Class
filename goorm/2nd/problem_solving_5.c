// [문제해결 2-5] 알파벳빈도

#include <stdio.h>
#include <string.h>

// a = 97
// A = 65
// 'a'-'A' = 32

// A를 입력받으면 65번째 인덱스에 +1
int main() {
	int i,t;
	char s[1000001];
	int a[100]={0, };
	scanf("%s", s);
	for(i=0; s[i]!='\0'; i++) {
		// printf("%c", s[i]);
		t=s[i]; // t에 65(A) 저장
		a[t]=a[t]+1;
	}
	// i=0;
	// while(s[i]!='\0') {
	// 	t=s[i];
	// 	a[t]=a[t]+1;
	// 	i++;
	// }
	for(i=65; i<=90; i++) { // for(i='A'; i<=90; i++)
		if(a[i]>0) {
			printf("%c : %d\n", i,a[i]);
		}
	}
	
	return 0;
}