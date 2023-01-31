// [문제해결 7-1] 단순연결리스트 구현

/* TMI : 메모리 구조
코드 영역 : main()

데이터 영역 : 전역변수, 정적변수

힙 영역 : 동적할당(malloc), 포인터

스택 영역 : 지역변수, 매개변수

*/

// 연결리스트 : 메모리에(힙영역)에 비연속적으로 저장됨 

#include <stdio.h>
#include <stdlib.h>

typedef int element;
//1. 연결리스트 구조체 정의
typedef struct Node{
	element data;
	struct Node* next; // Node 구조체를 가르키는 next 변수
}Node;

Node* insertFirst(Node* head, element data){ // 새로 생성된 Node의 시작주소를 반환
	//2. 첫위치 삽입 코드 작성
	Node* newnode = (Node*)malloc(sizeof(Node)); // 1. 새로운 노드 생성
	newnode->data = data; // 새로운 노드에 값 저장
	newnode->next = head; // 새로운 노드의 next에 원래 첫 번째 노드의 주소값을 준다
	head = newnode; // head값을 newnode로 변경
	return head; // 변경된 헤드 포인터 반환
}

Node* insert(Node* head, Node* pre, element data){
	//3. 중간위치(pre 다음 위치 )삽입
	Node* newnode = (Node*)malloc(sizeof(Node)); // 1. 새로운 노드 생성
	newnode->data = data; // 2. 새로운 노드에 값 저장
	newnode->next = pre->next; // 3. 새로운 노드의 next에 pre의 next가 가르키는 노드의 주소값을 준다 : 새로운 노드가 pre 노드가 가르키던 것을 가르킨다
	pre->next = newnode; // 새로운 노드의 주소값을 pre의 next에 준다
	return head;
}

Node* deleteFirst(Node* head){
	//4. 첫위치 삭제 코드 작성 : head를 받아서 head가 가르키고 있는 node를 삭제 : 그 다음 노드를 가르키게 한다
	Node* removed = head; // head값이 없어지면 안되니까 
	head = head->next; // head->next == removed->next,  
	free(removed);
	removed = NULL; 
	return head;
}

Node* delete(Node* head, Node* pre){
	//5.프리가 가리키는 다음 노드를 삭제
	Node* removed = pre->next; // 삭제할 노드는 pre의 다음 노드 
	pre->next = removed->next; // 삭제할 노드가 가르키는 노드를 pre가 가르키는 노드로 바꾼다
	free(removed); //  
	removed = NULL; // 삭제된 Node에 Null값을 넣어서 삭제한다
	return head; 
}

void printList(Node* head){
	Node* p = head;
	while(p!=NULL) {
		printf("%d->", p->data);
		p = p->next; // 중요 !!!!!!!!!!!!!!!이거 100% 시험에 나옵니다!!!!!!!!!!!!!!!!!!, 다음 노드를 가르키기 위해서, 빈칸 3줄정도로 비워놓음
	}
	//6.head가 널이 아니면 노드데이터 출력
	printf("NULL\n");
		
}

int main(){
	Node* head = NULL;
	Node* temp = NULL;
	
	printf("[첫 위치 삽입]\n");
	for(int i = 0;i<5;i++){
		head = insertFirst(head, i);//7. 첫위치에 i 삽입
		printList(head);
		if (i==2) temp = head; //데이터가 2인 노드 주소 저장
	}
	
	printf("[중간위치 삽입]\n");
	head = insert(head, temp, 100);//8. temp 다음 위치에 100 저장
	printList(head);
	
	printf("[중간위치 삭제]\n");
	head = delete(head, temp);//9. temp 다음위치 노드 삭제
	printList(head);
	printf("[첫 위치 삭제]\n");
	for(int i=0;i<5;i++){
		head = deleteFirst(head);//10. 첫위치 노드 삭제
		printList(head);
	}
	return 0;
}
