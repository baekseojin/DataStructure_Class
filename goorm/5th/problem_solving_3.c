// [문제해결 5-3] 스택의 활용

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 20

typedef char element;
//스택 구조체 작성
typedef struct {
	element data[STACK_SIZE];
	int top;
}Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
 	Stack s;
	char str[20];
	printf("문자열 입력 : ");
	scanf("%s", str);
	initStack(&s);
	//문자열을 입력받아 거꾸로 출력
	for(int i=0; str[i]!='\0'; i++) { // i<strlen(str); 
		push(&s, str[i]);
	}
	for(int i=0; str[i]!='\0'; i++) {
		printf("%c", pop(&s));
	}
}

void initStack( Stack *s ){ // 스택 초기화하기
	 s->top = -1;
}
int isFull( Stack *s ){ // 스택이 가득 차있으면 true 반환
	 return s->top == STACK_SIZE-1;
}
int isEmpty( Stack *s ){ // 스택이 비어 있으면 ture 리턴
 	return s->top == -1;
}
void push(Stack *s, element c){
	if(isFull(s)) {
		printf("Stack is Full\n");
		return ;
	}
	s->top++;
	s->data[s->top] = c;
}
element pop( Stack *s ){
	if(isEmpty(s)) {
		printf("Stack is Empty\n");
		return -1;
	}
	return s->data[s->top--]; 	
}