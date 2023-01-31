// 1. 단순 연결리스트 구현

/*
	- ADT : 추상화 데이터 타입
	- 연결리스트에서 삽입/삭제 : 포인터 값(링크)만 변경시킴으로써 연산을 쉽게 수행(노드 이동 X)
	  연결리스트에서 탐색 : 배열보다 느리다
	
	- head는 없어도 되는 변수(시작주소를 저장함)
	비어있는 부분을 찾아서 할당(할당되는 위치 랜덤) ->
	
	코
	데
	힙 (동적할당[포인터, malloc]) : 비어있는 공간에 아무데나 할당, 랜덤한 위치에 데이터 저장 
	스
	
*/

// 동적으로 구조체 생성하기
#include<stdio.h>
#include<stdlib.h>

typedef int element;
//1)Node 구조체를 전역에 정의
typedef struct Node {
	element data;
	struct Node* next; // Node 구조체를 가르키는 next 변수 
}Node;

int main(){
	Node *n1, *n2 ,*n3, *head;
    n1 = (Node*)malloc(sizeof(Node)); // (Node*) : 강제 형변환, 원래 malloc은 void로 반환하기 때문에
    n2 = (Node*)malloc(sizeof(Node));//Node구조체 n2 동적할당
	n3 = (Node*)malloc(sizeof(Node));//Node구조체 n3 동적할당
	// printf("%p %p %p", n1,n2,n3);
	n1->data = 10; // 2) n1의 데이터에 10을 저장
    n1->next = n2; // 3) n1의 다음 노드 주소 next에 n2를 저장
 	n2->data = 20; // 4) n2의 데이터에 20을 저장
	n2->next = n3; // 5)n2의 다음 노드 주소 next에 n3 저장
  	n3->data = 30; // 6) n3의 데이터에 30을 저장
	n3->next = NULL; // 7) n3의 다음 노드 주소 next에 NULL 저장
    head = n1; // 포인터 주소, Node의 시작주소
    while( head != NULL ){ // head에 값이 있을때, 즉 null이 아닐때
        printf("%d->", head->data); 
       	//9) head에 다음 노드 주소 저장
		head = head->next; // head는 head의 다음 주소를 가르킨다
    }
	return 0;
}
