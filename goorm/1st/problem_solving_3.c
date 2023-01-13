// [문제해결 01-03] 배열 원소 입력 및 출력

#include <stdio.h>

int main() {
	int a[100]={0}, num, i, size=0;
	for(i=0; i<100; i++) {
		scanf("%d", &num);
		if(num == 0) {
			size = i; // size = 4
			break;
		}
		else {
			a[i] = num;
		}
	}
	for(i=size-1; i>=0; i--) {
		printf("%d ", a[i]);
	}
	
	return 0;
}