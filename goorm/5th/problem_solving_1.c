// [문제해결 5-1] 스택의 구현


/* 설명
ADT
A = 추상화
D = 데이터
T = 타입

push(data);
pop();
inFull(stack 이름)
isEmpty(stack 이름)
peek() : 조회하다, 맨 위 데이터 출력하지만 없어지지는 않는다 
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define MAX_STACK_SIZE 100

// typedef int element; //int를 element로 재정의
// element	stack[MAX_STACK_SIZE]; //1차원 배열로 스택 정의
// //전역변수로 스택 선언
// int top = -1; // 제일 위 데이터의 위치

// bool isEmpty() {
// 	if(top == -1) return 1; // 비어있는게 참이다 
// 	else return 0; // 비어있는게 거짓이다
// }
// bool isFull() {
// 	if (top == MAX_STACK_SIZE-1) return 1; // 다 찬게 참이면 1 반환
// 	else return 0; // 다 안찼으면 0 반환
// }	 
// void push(element item){ // 스택에 데이터 삽입
// 	top = top + 1;
// 	stack[top] = item; 
// }
// element pop(){ //반환후 제거
// 	element temp = stack[top];
// 	top = top - 1;
// 	return temp;
	
// }
// element peek(){ //반환만
// 	element temp = stack[top];
// 	return temp;
// }
// int main(){
// 	push(1);
// 	push(2);
// 	push(3);
// 	printf("%d\n",pop()); // 3 출력 후 제거 
// 	printf("%d\n",peek()); // 2 출력하고 그대로 있다
// 	printf("%d\n",pop()); //  2 출력 후 제거
// 	return 0;

// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

typedef int element; //int를 element로 재정의

typedef struct {
	int data[MAX_STACK_SIZE]; 
	int top;
} Stack;
Stack s;
element	stack[MAX_STACK_SIZE]; //1차원 배열로 스택 정의
//전역변수로 스택 선언
int top = -1; // 제일 위 데이터의 위치

bool isEmpty() {
	if(top == -1) return 1; // 비어있는게 참이다 
	else return 0; // 비어있는게 거짓이다
}
bool isFull() {
	if (top == MAX_STACK_SIZE-1) return 1; // 다 찬게 참이면 1 반환
	else return 0; // 다 안찼으면 0 반환
}	 
void push(element item){ // 스택에 데이터 삽입
	s.top = s.top + 1;
	s.data[s.top] = item; 
}
element pop(){ //반환후 제거
	element temp = s.data[s.top];
	s.top = s.top - 1;
	return temp;
	
}
element peek(){ //반환만
	element temp = s.data[s.top];
	return temp;
}
int main(){
	s.top = -1;
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop()); // 3 출력 후 제거 
	printf("%d\n",peek()); // 2 출력하고 그대로 있다
	printf("%d\n",pop()); //  2 출력 후 제거
	return 0;

}
