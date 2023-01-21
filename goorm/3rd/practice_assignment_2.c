// [실습과제 3-2] 배열 달팽이

#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num); // 3 입력
	int arr[10][10] = { 0 };
	int cnt = 0;
	int len = num;
	int row = 0;
	int col = -1;
	int op = 1;
	
	while(1) {
		for(int i=0; i<len; i++) {
			col += op;
			arr[row][col] = ++cnt;
		}
		if(--len == 0) {
			break;
		}
		for(int i=0; i<len; i++) {
			row += op;
			arr[row][col] = ++cnt;
		}
		op = -op;
	}
	
	for(int i=0; i<num; i++) {
		for(int j=0; j<num; j++) {
			printf("%2d", arr[i][j]);
		}
		putchar('\n');
	}
	return 0;
}