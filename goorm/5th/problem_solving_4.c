// [문제해결 5-4] 스택의 응용(괄호 구현)

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef char element;
//스택 구조체 정의
typedef struct {
	int top;
	element data[STACK_SIZE];
}Stack; 

int checkTest(char expr[]); // expr : 수식
void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
	Stack s; // 구조체 변수 선언
	char expr[20];
	
	printf("괄호포함 수식 입력 : ");
	scanf("%s", expr);
	if (checkTest(expr)) printf("성공"); // 만역 여는 괄호이면 push  
	else printf("실패"); // 만약 닫는 괄호이면 pop == ch
	return 0;
	
}
void initStack( Stack *s ){
	s->top = -1;
}
int isFull( Stack *s ){
	return s->top == STACK_SIZE-1;
}
int isEmpty( Stack *s ){
	return s->top == -1;
}
void push( Stack *s, element c ){
	if(isFull(s)){
		printf("stack is full\n");
		return ;
	}
	s->top++;
	s->data[s->top] = c;
}
element pop( Stack *s ){
	if(isEmpty(s)){
		printf("stack is empty\n");
		return 0;
	}
	return s->data[s->top--]; 
}
int checkTest(char expr[]){
	int i;
	Stack s;
	initStack(&s);
	char ch,open_ch;
  for(i=0;expr[i]!='\0';i++) {
		ch = expr[i];
		switch(ch){
			case '(': 
			case '[':
			case '{':
				push(&s, ch);
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0; // 비어있으면 0 출력
				open_ch = pop(&s); // open_ch = 꺼낸 것을 저장
				if ((open_ch == '(' && ch != ')') ||
					  (open_ch == '[' && ch != ']') ||
					  (open_ch == '{' && ch != '}') ) {
					return 0;
				}
				// printf("open_ch=%c\n",open_ch);
				break;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}