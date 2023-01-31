// [실습과제 7-4] 단순리스트 역순으로 출력

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void printList(Node *head){
	Node* p = head; 
  // 연결 리스트를 순서대로 출력하는 연산
	for(Node *p = head; p!=NULL; p = p->next) {
		if(p->next == NULL) {
			printf("%d", p->data);
		}
		else {
			printf("%d->", p->data);
		}
	}
	printf("\n");
}
Node* reverse(Node *head){
	Node *p,*q, *r;
  // 연결 리스트를 역순으로 연결하는 함수 작성
	p = head;
	q = NULL;
	while(p!=NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}

// 첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, int data ){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = head;
	head = p;
	return head;
}

int main(){
	Node* head = NULL ;
	for(int i=10;i<=50;i+=10){
	 	head = insertFirst(head,i); // insertFirst 함수호출
		printList( head );
	}
	head = reverse(head);//역순으로 연결하는 함수 호출
	printf("역순으로 출력\n");
	printList( head );	
	return 0;
}