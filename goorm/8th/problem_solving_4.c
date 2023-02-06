// [문제해결 8-4] 이중원형연결리스트 문제

/*
시험문제 나옴 !!!!!!!!!!!!!!!!!!!!111
결과를 낼 수도 있고, 빈칸을 낼 수도 있음
*/
// head : 
// phead : 
#include <stdio.h>
#include <stdlib.h>
// 이중연결 노드 구조체 정의
typedef struct DNode {
	int index; // 풍선 번호
	int data; // 풍선의 값
	struct DNode* prev;
	struct DNode* next;
}DNode;

// 이중연결리스트 Head 구조체 정의
typedef struct Head {
	int size;
	DNode* link; // 연결리스트 시작주소
}Head;

void insertLast(Head* head, int data);

void deleteNode(Head* head);

int main() {
	
	Head* head = (Head*)malloc(sizeof(Head)); // 연결 리스트의 헤더 생성
	head->link = NULL;
	head->size = 0;
	
	// 원형 이중 연결 리스트 사이즈(풍선개수)를 입력
  int size,num;
	scanf("%d", &size); // 5 입력
  
	// 숫자를 입력받아 리스트에 풍선노드 추가
	for (int i = 0; i < size; i++){
		scanf("%d", &num); // 3, 2, 1, -3, -1
 		// 리스트에 노드에 삽입 함수 호출
		insertLast(head, num);
	}
	
 for (int i = 0; i < size; i++){
		// 리스트 노드 삭제
	 	deleteNode(head);
	}
	
	free(head->link);
	free(head);
  return 0;
}

void insertLast(Head* phead, int data)
{
	// 리스트에 새로 추가될 노드s
	DNode* head = phead->link; // head를 새로 지정하기 위해 phead->link의 값을 준다
	DNode* newNode = (DNode*)malloc(sizeof(DNode)); // 동적할당
	newNode->data = data;
	newNode->index = phead->size + 1; // 리스트 크기 +1

	// 리스트 마지막 위치에 노드 삽입
	if (head == NULL){ // 리스트에 최초삽입시 초기화
		phead->link = newNode; // head가 가르키는게 자기 자신
		newNode->prev = newNode; // 자기 자신을 가르키게
		newNode->next = newNode; // 자기 자신을 가르키게
	}
	else{	// head가 NULL이 아닐 경우, 즉 이미 풍선이 있을 경우
		newNode->prev = head->prev; // 새로운 노드의 prev를 head의 prev(세번쨰 노드)로
    newNode->next = head; // head를 새로운 노드의 next로
    head->prev->next = newNode; // head->prev(주소 100)의 next를 newNode로 한다
    head->prev = newNode; //       
		}
	// 리스트 사이즈를 증가시켜 인덱스로 활용
	phead->size++;
}

void deleteNode(Head* phead){
	DNode* head = phead->link; // 1번풍선 3의 값을 가지고 있음
	int index = head->index; //  풍선의 번호
	int count = head->data; // 풍선 안에 들어 있는 숫자의 값
	printf("%d ", index);
	// 풍선이 하나 남아 있을 때 종료
	if (phead->size == 1){
		phead->size--;
		return;
	}
	// 삭제할 풍선을 가리키는 노드
	DNode* removed = head; // 삭제할 노드 주소 저장
	DNode* p = head; // 순회할 시작 주소 저장
	if (count > 0){ // 양수일때
		for (int i = 0; i < count; i++){
			p = p->next; //다음노드 방향으로 이동
			
			if (p == removed){ // 터트릴 풍선 skip
				p = p->next;
			}
		
		}
	}
	else
	{
		for (int i = 0; i < count * (-1); i++){
			p = p->prev; // 음수일때 이전 노드 방향 이동
		 	// 탐색 한 위치가 삭제할 노드이면  skip
			if (p == removed) {
				p = p->next; 
			}
		}
	}
	phead->link = p; // 마지막 순회한 위치를 새로운 head 주소로 저장
	removed->prev->next = removed->next; // 삭제할 다음노드와 연결
	removed->next->prev = removed->prev;// 삭제할 이전노드와 연결  
  free(removed);
	phead->size--;
}

void printList(Head* phead){
	DNode* p = phead->link;
	do{
		printf("[%d] ->",p->data);
		p = p->next;	
	}while(p!=phead->link);
}