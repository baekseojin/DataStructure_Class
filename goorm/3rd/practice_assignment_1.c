// [실습과제 3-1] 배열대각선 출력

#include <stdio.h>

int arr[201][201]={0};
int main(){
	int i, j, n, m, num, count=1;
	scanf("%d %d",&n, &m);
	//배열의 인덱스 위치에 값을 저장 코드 작성
	for(num=0; num<n+m-1; num++) {
		for(j=0; j<m; j++) {
			for(i=0; i<n; i++) {
				if(i+j==num) {
					arr[i][j] = count;
					count++;
				}
			}
		}
	}
	// 배열의 결과를 출력
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}