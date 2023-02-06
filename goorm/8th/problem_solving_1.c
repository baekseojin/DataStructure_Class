// [문제해결 8-1] 원형연결리스트 구현

#include <stdio.h>
#include <stdlib.h>
typedef int element;

// 0) Node구조체 작성
typedef struct Node {
	element data;
	struct Node* next; // Node 구조체를 가르키는 next 변수
}Node;

void printList(Node* head){
	Node *p = head->next; // 1) 처음위치부터 출력
	int cnt = 0;
	if (head == NULL) return;
	do {
		if(p == NULL) break;
			printf("%d->", p->data);// 2) 데이터 출력
			p = p->next; // 3) ptr을 다음 주소로 저장
			cnt++;
	}//while(p != head->next); // 4)조건
	while(cnt < 10);
	printf("\n");
}

Node* insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node)); //Node 동적할당
	node->data = data; 
	if (head == NULL) { // 노드가 아무것도 없을 때 
		head = node; // head의 주소로 새로운 노드의 주소 저장
		head->next = head; // 새로운노드의 다음 주소로 head 저장
	}
	else { // 다른 노드가 있을 때
		node->next = head->next; // 새로운 노드가 맨 앞 노드를 가르키게 head가 가르키는 노드의 주소값을 준다	 
		head->next = node; // head의 다음 노드 주소로 새로운 노드의 주소 저장
	}
	return head;
}

Node* insertLast(Node* head, element data){
	
	Node* node = (Node*)malloc(sizeof(Node)); //노드 동적할당
	node->data = data;
	
	if (head == NULL){
		head = node; // head의 주소로 새로운노드의 주소 저장
		head->next = head; // 새로운노드의 다음 주소로 head 저장
	}
	
	else {
		node->next = head->next; // 새로운 노드가 맨 앞을 가리키게 주소값을 준다
		head->next = node; // 새로운 노드의 주소를 head가 가르키게 
		head = node; // 새로운 node를 head로 만든다
	}
	
	return head;
}

int main() {
	Node *head = NULL, *tail, *ptr;
	printf("처음위치에 연결\n");
	for(int i = 1; i<5; i++){
		head = insertFirst(head, i); // 첫위치에 삽입하는 함수 호출	
	}
	printList(head);
	printf("마지막위치에 연결\n");
	for(int i = 11;i< 15;i++){
		head = insertLast(head, i);//마지막 위치에 삽입하는 함수 호출	
	}
	printList(head);

	return 0;
}