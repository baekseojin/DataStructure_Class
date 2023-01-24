// [문제해결 3-1] 배열의 저장과 출력

#include <stdio.h> 
int main(){
	int a[101][101]={0};
	int i,j,num,n,m;
	scanf("%d",&n);
	num = 1;
	//1. 배열에 값을 저장하는 코드 작성
	for(i=1; i<=n; i++) { 
		if(i%2==1) { // i가 홀수면 정상적으로 출력
			for(j=1; j<=n; j++) { // 1, 2, 3
				a[i][j]=num++;		
			}
		}
		else {
			for(j=n; j>=1; j--) { // j가 짝수면 빽으로 출력
				a[i][j]=num;
				num++;
			}
		}
	
	}
	//2. 배열결과를 출력하는 코드 작성
	for(i=1; i<=n; i++) { // 1
		for(j=1; j<=n; j++) { // 1, 2, 3
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}