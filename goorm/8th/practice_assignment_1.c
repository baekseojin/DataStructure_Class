// [실습과제 8-1] 연결리스트로 스택구현

#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 1) 노드의 구조체 정의
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

//2) 스택리스트의 시작 구조체 정의
typedef struct LinkedStackType {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s){
	 s->top = NULL; 
}

int is_empty(LinkedStackType* s){
	return (s->top == NULL);
}

int isFull(LinkedStackType* s){
	return 0;
}

void push(LinkedStackType* s, element data){
  StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); // 동적할당
	temp->data = data; 
	temp->link = s->top; 
	s->top = temp; 
}

element pop(LinkedStackType* s){
	element data;
	StackNode* temp;
	if (is_empty(s)){
		printf("Stack is Empty\n");
	}
	else{
		StackNode *temp = s->top;
		s->top = s->top->link;
		data = temp->data;  
		free(temp);
		 
	}
}
void print_stack(LinkedStackType* s){
	StackNode* p = s->top;//;
	while(p!=NULL){
		printf("%d->",p->data);
		p = p->link;//
	}
	printf("NULL\n");
}
int main() {
	LinkedStackType s ;
	init(&s);
	push(&s,1); 
	print_stack(&s);
	push(&s,2); 
	print_stack(&s);
	push(&s,3); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	pop(&s); 
	print_stack(&s);
	return 0;
}