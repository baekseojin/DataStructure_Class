// [문제해결 5-2] 스택의 구현(2)

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

typedef int element; // element 가 곧 int 임

//Stack 구조체 구현
typedef struct {
	element data[STACK_SIZE]; // int data[10];
	int top ;
}Stack;
// 정의, 메모리에 할당 X

int isFull( Stack *s );
int isEmpty( Stack *s );
void push(Stack *s, element data);
int pop( Stack *s );
void initStack(Stack* s );

int main(){
	int menu;
	element data;
	Stack s; // 할당 
	initStack( &s );
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		switch( menu ){
			case 1 : // 1번을 누를 경우 데이터 입력 받아서 push 
				printf("데이터 입력 : ");
				//입력 
				scanf("%d", &data);
				//스택에 입력
				push(&s, data); 
				break;
			case 2 :
        data = pop(&s); // 스택에서 출력
        if( data )
				  printf("pop 데이터 : %d\n", data);
				break;
      case 0 :
        break;
			default :
				printf("잘못된 입력 입니다. \n");
				break;
		}
	}while( menu );
}
int isFull( Stack *s );
int isEmpty( Stack *s );
void push(Stack *s, element data);
int pop(Stack *s);

void initStack( Stack *s ){  // top 포인터를 -1로 초기화
	s->top = -1;
	// (*s).top = -1;
}

int isFull( Stack *s ){   // 스택이 가득 차 있으면 true 리턴
	// return (s->top == STACK_SIZE-1) return 1;
	// else return 0;
	return s->top == STACK_SIZE-1;
}

int isEmpty( Stack *s ){   // 스택이 비어 있으면 true 리턴
	return s->top == -1;
}

void push( Stack *s, element data ){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
	if(isFull(s)) { // 주소 s로 들어왔기 때문에 그냥 s 
		printf("스택이 가득찼습니다.\n");
		return;
	}
	s->top++;
	s->data[s->top] = data;
}

element pop( Stack *s ){  //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
	element temp;
	if(isEmpty(s)) {
		printf("스택이 비었습니다.\n");
		return 0;
	}
	temp = s->data[s->top];
	s->top--;
	return temp;
	// return s->data[s->top--];
}