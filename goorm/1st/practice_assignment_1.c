// [실습과제1-1] 1차원배열(인덱스이용)

#include <stdio.h>

int arr[10000001]; // main 함수에 배열을 선언하면 크기가 너무 커서 스택 오버플로우 발생(지역변수는 스택 영역에 저장)
// 스택 오버플로우 방지를 위해 전역변수(데이터 영역) 선언

int main()
{
	int n, m, num;
	scanf("%d", &n); 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num); 
		arr[num] = 1; // arr[2, 52, 23 55, 100] = 1을 넣는다
	}

	scanf("%d", &m); 
	for(int j = 0; j < m; j++)
	{
		scanf("%d", &num);  
		printf("%d ", arr[num]);
	}	
	return 0;
}