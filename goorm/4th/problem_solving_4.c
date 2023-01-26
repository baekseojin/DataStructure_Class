// [문제해결 4-4] 원점과 가장 가까운 좌표

/*
루트 : sqrt
제곱 : pow(3, 2) 3의 2제곱 = 9
sqrt((x-0) + (y-0)) 

1. 구조체 정의 :
typedef struct {
	int x;
	int y;
} point;

2. 구조체 선언 : 
point p; 선언할 때 메모리에 저장


q->x (포인터로 선언된 자료형)

(*q) x

*/

// #include <stdio.h>
// #include <math.h>
// #define N 5


// typedef struct point{
// 	int x,  y;
// } POINT;

// POINT origin = { 0, 0}; // point 형의 구조체로 변수를 선언하고 (0,0)으로 초기화 = 원점

// int main() {
// 	int min = 99999999; // 가장 작은 거리를 구하기 위해 큰 값 저장
// 	double dt;
// 	int mindex;
// 	POINT p[5];
// 	for(int i=0; i<5; i++) {
// 		scanf("%d %d", &p[i].x, &p[i].y);
// 	}
// 	for(int i=0; i<5; i++) {
// 		scanf("(%d %d)\n", &p[i].x, &p[i].y);
// 	}
// 	for(int i=0; i<5; i++) {
// 		dt = sqrt( pow(p[i].x-0, 2) + pow(p[i].y-0, 2) ); // 두 점 사이의 거리 구하는 코드
// 		dt = dt + p[i].x + p[i].y; // 
// 		if(dt<min) { // 만약 거리(dt)가 min보다 작다면 
// 			min = dt; // 거리를 min에 넣어라 (거리가 가장 작은 값 = 원점에서 가장 가까움)
// 			mindex = i; // 인덱스 번호를 
// 		}
// 	}
	
// 	printf("원점에서 가장 가까운 좌표 : ");
// 	printf("(%4d, %4d)\n", p[mindex].x, p[mindex].y);
// 	return 0;
// }



#include <stdio.h>
#include <math.h>
#define N 5


typedef struct point{
	int x,  y;
} POINT;

POINT origin = { 0, 0}; // point 형의 구조체로 변수를 선언하고 (0,0)으로 초기화 = 원점


void inputPoint(POINT *p) {
	scanf("%d %d", &p->x, &p->y); // 포인터에서 구조체 접근
}

double distance(POINT *p, POINT *q) {
	return sqrt( pow((p->x - q->x), 2) + pow((q->y - p-y), 2) ); // 두 점 사이의 거리 구하는 코드
}
void outputPoint(POINT *p) {
	printf("(%4d, %4d)\n", p->x, p->y);	
}

int main() {
	int min = 99999999; // 가장 작은 거리를 구하기 위해 큰 값 저장
	double dt;
	int mindex = 0;
	POINT p[5];
	for(int i=0; i<5; i++) {
		inputPoint(p+1);
	}
	for(int i = 0; i<N; i++) {
		outputPoint( p+i );
	}
	for(int i=0; i<5; i++) {
		if( distance(&origin, &p[mindex] ) >= distance(&origin, p+i)) {
			if((p[mindex].x + p[mindex].y) > (p[i].x + p[i].y)) {
				mindex = 1;
			}
		}
	}
	
	printf("원점에서 가장 가까운 좌표 : ");
	outputPoint( p+ min );
	return 0;
}

