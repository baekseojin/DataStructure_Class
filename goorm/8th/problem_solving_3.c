// [문제해결 8-3] 이중연결리스트

/*

이중연결 리스트 : 그 자체가 원형 리스트
시험문제 나옴 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
결과를 낼 수도 있고, 빈칸을 낼 수도 있음( 둘 다 알고 있자 )

*/

#include <stdio.h>
#include <stdlib.h>
typedef int element;

// 이중연결리스트 노드 구조체 정의
typedef struct DNode {
	element data;
	struct DNode* prev;
	struct DNode* next;
}DNode;

void init(DNode* phead){ // 헤드노드 초기화 
	phead->next = phead; // 헤드노드의 next를 head노드 주소로 저장, 자기 자신을 참조하도록 함 
	phead->prev = phead; // 헤드노드의 prev를 head노드 주소로 저장, 자기 자신을 참조하도록 함
}

void dinsert(DNode* before,element data){ // before 다음노드로 삽입		
	DNode* newnode = (DNode*)malloc(sizeof(DNode)); // 동적할당
	newnode->data = data; // 데이터 저장
	newnode->prev = before; // prev에 이전노드 주소값 저장, 새로운 노드의 prev에는 원래 노드(before)의 주소값 저장
	newnode->next = before->next; // 이전노드의 next값 저장, 새로운 노드의 next에는 원래 노드(before)의 next값 저장
	before->next->prev = newnode; // 이전노드의 넥스트 노드의 prev값을 새로운 노드 주소값으로 저장, before(A)의 next(C)의 prev(B, newnode)
	before->next = newnode; // 이전노드의 next값을 새로운 노드 주소값으로 저장;
}

void ddelete(DNode* head, DNode* removed){
	// 삭제할 노드를 removed로 저장
	if(removed == head) return;
	removed->prev->next = removed->next; // 삭제할 노드의 next값으로 저장, 삭제할 노드의 이전 노드(prev)의 next(이전 노드가 가르키는 노드) = removed->next(삭제할 노드의 다음 노드) 
	removed->next->prev = removed->prev; // 삭제노드의 prev값으로 저장 
	free(removed);
}

void printDlist(DNode* phead){
	DNode* p;
	for(p=phead->next; p!=phead; p=p->next) { // 초기값: phead->next, phead위치가 아니면 출력
		printf("<-| |%d| |->",p->data);
	}
	printf("\n");
}

int main() {
	DNode* head = (DNode*)malloc(sizeof(DNode)); // 헤드노드 동적할당    
	init(head); // 헤드노드 초기화
	printf("추가단계\n");
	for(int i = 0;i< 5;i++){
		dinsert(head, i);
		printDlist(head);
	}
	printf("삭제단계\n");
	for(int i = 0;i<5;i++){
		printDlist(head);
		ddelete(head, head->next);
	}
	free(head);
	return 0;
}