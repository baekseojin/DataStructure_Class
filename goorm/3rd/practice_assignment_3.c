// [실습과제 3-3] 배열의 합

#include <stdio.h>

int main() {
	int a,b,c, x1, y1, x2, y2;
	int arr[300][300];
	scanf("%d %d", &a, &b);
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}
	scanf("%d", &c);
	for(int i=0; i<3; i++) {
		int sum = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i=x1; i<=x2; i++) {
			for(int j=y1; j<=y2; j++) {
				sum += arr[i][j]; 
			}
		}
		printf("%d\n", sum);
	}
	
	
	return 0;
}