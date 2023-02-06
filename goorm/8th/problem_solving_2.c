// [문제해결 8-2] 원형연결리스트(카드문제)

#include <stdio.h> 
#include <stdlib.h>
typedef int element;

//0)노드 구조체 작성
typedef struct Node {
	element data;
	struct Node* next;
}Node;

void printList(Node* head) {
	Node *p = head->next; // 출력은 앞에서부터 하기 때문에 p에 리스트의 첫위치(head->next) 저장
	int count = 0;
	if (head == NULL) return ;
	do {
		if(p == NULL) break;
		printf("%d->", p->data);
		p = p->next; // 다음 노드값 저장
 }while(p != head->next); // p의 값이 첫위치가 아니면
 // }while(cnt <10);
	printf("\n");
}

Node* insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//새노드 동적할당
	node->data = data; // 새로운 노드에 데이터 저장
	if (head == NULL){ // 리스트에 노드가 없는 경우 자기가 자기를 가르킨다
		head = node; // 새로운 노드의 주소값을 head한테 준다
		head->next = head; // 새로운 노드의 주소를 스스로 가르키게 next한테 준다 = 자신을 순환 참조
	}
	else { // 리스트에 노드가 있는 경우
		node->next = head->next; // 맨 끝 노드가 가르키는 노드를 새로운 
		head->next = node;// 새로운 노드 주소값 	 
	}
	return head;
}

Node* insertLast(Node* head, element data) {
	Node* node = (Node*)malloc(sizeof(Node)); // 새노드 동적할당
	node->data =data;
	
	if (head == NULL) {
		head = node; //새로운 노드주소값
		head->next = head;//자신을 순환참조
	}
	
	else {
		node->next = head->next; // 리스트의 첫 위치
		head->next = node;// 새노드 주소
		head = node;//새로운 head 주소 리턴
	}
	return head;
}

Node* changeCard(Node* head){
	Node* removed = head->next; // 노드삭제위치 저장
  head->next = head->next->next; // 삭제된 다음 위치와 연결, == (removed->next)
	free(removed);
	return head->next; // 새로운 헤드값으로 리턴
}

int main() {
	Node* head = NULL, *p;
	int n;
	printf("카드개수 입력\n");
 	scanf("%d",&n);
//	printf("마지막위치에 연결\n");
	for(int i = 1;i <= n;i++){
		head =  insertLast(head, i); // 노드 삽입함수 호출
	}
//	printf("head노드 = %d\n",head->data);
	while(head->next != head){
		head = changeCard(head); // 카드 제거함수 호출
		printList(head);
	}
	 printf("마지막 카드번호 : %d", head->data);
	return 0;
}
