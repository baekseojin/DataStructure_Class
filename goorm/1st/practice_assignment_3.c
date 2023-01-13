// 실습과제[1-3] 1차원배열(최대값)

#include <stdio.h>
int main() {
	char input[100];
	int arr[9];
	int temp = 0;
	int j;
	for(int i=0; i<9; i++) {
		scanf("%d", &arr[i]);
	}
	for(j=0; j<9; j++) {
		if(temp<=arr[j]) {
			temp = arr[j];
		}
	}
	printf("%d\n%d", temp, j-1);
	
	return 0;
}