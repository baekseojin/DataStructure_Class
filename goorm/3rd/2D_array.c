// [3-1] 2차원 배열

#include <stdio.h>
// 예제1, 2 ,3번을 실행하여 결과를 확인하시오.

// 예제1 ==> 이 결과가 의미하는 것은? 행우선인가? 열우선인가?
// #include <stdio.h>

// int main(){
//     int i,j, a[2][3]={{10,20,30},{40,50,60}}; // 24byte
//     printf("배열전체의 크기 : %d\n",sizeof(a)); // 배열의 이름은 주소이다. 
//     printf("배열요소의 개수 : %d\n",sizeof(a)/sizeof(int)); // 24/4 == 6
// 		printf("%d\n", &a[1][0]-&a[0][0]); // **중요** 3이 출력 !!!!! 공간의 차이가 출력 
//     printf("배열요소의 값\n"); 
//     //배열의 값과 주소 출력
// 		for(i=0; i<=1; i++) {
// 			for(j=0; j<=2; j++) {
// 				printf("%4d %8X\n", a[i][j], &a[i][j]);
// 			}
// 		}
//     return 0; 
// }


// 예제2 - 2차원 배열 초기화 및 출력
// #include <stdio.h>
// int main(){
// 	int jumsu[2][4] = { { 80, 96, 83, 100 }, { 88, 100, 96, 98 }};
// 	int i, j;
// 	int row=2, col=4;
// 	for( i = 0 ; i < row ; i++ ){
// 		for( j = 0 ; j < col ; j ++ )
// 			printf( "%5d", jumsu[i][j] );
// 		printf("\n");
// 	}
// }


// 예제3 2차원 배열 입력 & 출력 코드를 완성하여 실행해 보자.
#include <stdio.h>
void inputArray( int a[][3], int r);
void outputArray( int a[][3], int r);
int main(){
	int array[4][3];
	int row = 4;
	
	inputArray( array, row );
	outputArray( array, row );
	return 0;
}
void inputArray(int a[][3], int r) {
	int i, j;
	for(i=0; i<r; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void outputArray(int a[][3], int r){
	int i, j;
	//2차원 배열 출력
	for(i=0; i<r; i++) {
	for(j=0; j<3; j++) {
		printf("%5d", a[i][j]); 
	}
	printf("\n");
	}
}


// 학생 3명의 4과목 점수를 입력받아  총점과 평균을 구하는 프로그램을 완성하고 제출하시오.

// #include <stdio.h>
// void inputArray( int a[][4], int row );
// int main() {
// 	int score[3][4];
// 	int i, j;
// 	int tot;
// 	double avg;
// 	//printf("학생 3명, 각각 네 과목의 점수를 입력하세요\n");
// 	inputArray(score, 3);
// 	//각 학생의 총점과 평균을 계산하여 출력
// 	for(i=0 ;i<3; i++) {
// 		tot=0;
// 		for(j=0; j<4; j++) {
// 			tot = tot + score[i][j];
// 		}
// 		avg = tot/4.;
// 		printf("총점 : %d, 평균 : %.2lf\n", tot, avg); // long float
// 	}
// 	return 0;
// }

// void inputArray( int a[][4], int row ) {
// 	int i, j;
// 	//각 학생의 점수를 row 번 입력받기
//   for(i=0; i<row; i++) {
// 		for(j=0; j<4; j++) {
// 			scanf("%d", &a[i][j]);
// 		}
// 	}  
// }

/* 입출력 예제 복붙하는 방법 
1. shift insert
2. 마우스로 붙여넣기
*/