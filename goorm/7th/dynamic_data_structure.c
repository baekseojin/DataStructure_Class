// 2. 동적 데이터 구조

/*
	int* p 는 int p[] 와 똑같음, 공간 지정 X
	p = (int*)malloc(sizeof(int)*100) : 메모리에 400byte 할당 == int p[100]
	무조건 Node가 생성될 때마다 동적할당을 해줘야 함
*/
// 함수를 활용해 node 동적으로 생성하기

#include<stdio.h>
#include<stdlib.h> // 동적할당

typedef int element;

typedef struct Node {
    element data;
    struct Node* next; // Node 구조체를 가르키는 next 변수
}Node;

Node *createNode( element data) { // 반환 타입이 Node니까 new가   
    Node* newnode;
		newnode = (Node*)malloc(sizeof(Node)); // 노드 크기 동적 할당
    newnode->data = data; // 노드의 데이터 저장
    newnode->next = NULL; // 노드->next 참조를 NULL저장, NULL이 없으면 무한 루프에 빠지거나 에러
	  return newnode;
}

void printAll( Node* ptr ){
    while( ptr ){ // 만약 ptr이 NULL값이 아니라면
				if (ptr->next != NULL){ //next 노드가 있으면(NULL값이 아니면) -> 출력
          printf("%d->", ptr->data); // 노드의 데이터 출력 
        	ptr = ptr->next;  // 다음노드의 주소로 저장
				}
			  else { // next node가 null값이면 
					printf("%d", ptr->data);// 노드의 데이터 출력
					return; // 프린트 종료
				}
    }
}

int main(){
  Node *head, *node1,*node2, *node3 ;
	node1 = createNode(12);//heard, node1, node2 노드 생성
	node2 = createNode(99);
	node3 = createNode(37);	
	//각 노드->next를 저장
	node1->next = node2;
	node2->next = node3; 
	//head 노드를 출력
  head = node1;
	printAll(head);
}