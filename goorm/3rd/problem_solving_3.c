// [문제해결 3-2] 피겨스케이팅 점수 계산

#include <stdio.h>
#include <stdlib.h> // rand 함수 사용을 위한 헤더파일

void genRandom( int a[][5], int r );
void outputArray( int a[][5], int r);
float averageScore( int *row, int size );

int main() {
   int score[4][5], i ;
   genRandom( score, 4 );
   outputArray( score, 4 );
   
   for( i = 0 ; i < 4 ; i ++ ){
      printf("선수 %d : %.2f\n", i+1,averageScore( score[i], 5) );
   }
   
   return 0;
} 
void genRandom( int a[][5], int r ){
   int i, j;
	 // rand 함수를 이용해 1~10 정수 생성
   for( i = 0 ; i < r ; i ++ )
      for( j = 0 ; j < 5 ; j ++ )
         a[i][j] = rand() % 10 + 1; // 10으로 나눈 나머지 + 1 (1~10) : 랜덤 함수 값에서 10으로 나눈 나머지는 10 미만이 됨(10으로 나누면 값은 0~9가 나오고, 거기에 1을 더하니 1~10 사이의 값 출력)
      
}
void outputArray( int a[][5], int r){
   // a배열의 r행 5열의 데이터 출력
   int i, j;
   for( i = 0 ; i < r ; i ++ ){
      for( j = 0 ; j < 5 ; j ++ )
         printf("%5d",a[i][j]);
      printf("\n");
      }
}
float averageScore( int *row, int size ){
   // 선수 한명의 점수를 입력 받아 절사 평균을 구하여 출력
   int max =0, min =0,i;
   float sum = 0;
   for(i=0; i<size; i++){
      sum += *(row+i);
      if(row[max] < row[i]) max = i;
      else if(row[min] > row[i]) min = i;
   }
   return (sum-row[max]-row[min])/(size-2);
   
   
}