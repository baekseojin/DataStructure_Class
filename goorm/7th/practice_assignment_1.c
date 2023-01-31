// [실습과제 7-1] 단순연결리스트 탐색

#include <stdio.h> // 201p(단어입력) + 203(탐색)
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data[100];
	struct Node* next;
}Node;

Node* insertFirst(Node* head, char* data) { // 새로 생성된 Node의 시작주소를 반환
	Node* newnode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성  
	strcpy(newnode->data, data); // 입력받은 데이터(melon)를 새 노드의 data에 넣는다, 받아온 데이터가 s
	newnode->next = head; // head(NULL)을 새로운 노드의 next에 넣는다(아직 또 다른 노드가 없기 때문에 next값을 NULL로 한다)
	head = newnode; // 새로운 노드의 주소값을 head로 설정, head가 새로운 노드를 가르키게
	return head; // 새로운 노드의 주소값을 반환
}

Node* insert(Node* head, Node* pre, char* data){
	
}

Node* deleteFirst(Node* head){
	
}

Node* delete(Node* head, Node* pre){
	//프리가 가리키는 다음 노드를 삭제
	
}

void printList(Node* head) {
	Node* p = head;
	while(p!=NULL) { // head의 값이 NULL값이 아니면
		printf("%s->", p->data); // 
		p = p->next; // 시험 100퍼센뚜 나옴 !!!!!!!!!!!!!!!!!!
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL; // 가르킬 노드가 아무것도 없는 상태
	Node* p; 
  char str[3][10] ={"melon","kiwi","appple"}; // 
	char find[10];
	head = insertFirst(head,str[0]); // melon 입력
	printList(head);
	head = insertFirst(head,str[1]); // kiwi 입력
	printList(head);
	head = insertFirst(head,str[2]); // appple 입력
	printList(head);
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find); 
	for (p=head; p!=NULL; p=p->next){
		// printf("%s\n", p->data);
		if (strcmp(p->data,find) == 0) printf("%s를 찾았습니다.",find);
	}
	return 0;
}

/*
#include <stdio.h>//201p(단어입력) + 203(탐색)
#include <stdlib.h>
#include<string.h>

// 1. 과일의 이름을 저장하는 단순 연결 리스트 작성
// 2. 특정 단어를 탐색하는 코드를 작성

typedef struct Node{
   char data[100];
   struct Node* next;
} Node;

Node* insertFirst(Node* head, char* data){
   Node* newNode = (Node* )malloc(sizeof(Node)); // 새로운 노드 동적할당 
   strcpy(newNode->data, data); // 새로운 노드의 data에, 전달받은 data를 복사해 넣음
   // 받아온 data가 문자열이므로 strcpy()를 사용해 newNode->data에 복사해 넣기!
   newNode->next = head;
   head = newNode;
   return head;
}

Node* insert(Node* head, Node* pre, char* data){
   
}

Node* deleteFirst(Node* head){

}

Node* delete(Node* head, Node* pre){
   //프리가 가리키는 다음 노드를 삭제
}

void printList(Node* head){
   Node* p = head;
   while(p != NULL){ // p가 가리키는 노드가 있는 동안
      printf("%s->", p->data); // p가 가리키는 노드의 data를 출력
      p = p->next; // ★ p의 값을 p의 next값으로 바꾸며 다음 값으로 이동
   }
   printf("NULL\n");
}

int main(){
   Node* head = NULL;
   Node* p;
  char str[3][10] = {"melon","kiwi","appple"};
   char find[10];
   
   //코드 작성
   head = insertFirst(head,str[0]); //melon 입력
   printList(head);
   
   head = insertFirst(head, str[1]); // kiwi 입력
   printList(head);
   
   head = insertFirst(head, str[2]); // appple 입력
   printList(head);
   
   printf("찾을 데이터를 입력하세요\n");
   scanf("%s", find); //  찾을 데이터(find) 입력받음
   
   for(p=head; p!=NULL; p=p->next){ 
      // p는 head(첫 번째)부터, p가 가리키는 노드가 있을 때까지 p는 다음 노드를 차례 차례 가리키기
      //printf("%s",p->data);
      if   (strcmp(p->data, find) == 0) printf("%s를 찾았습니다.", find);
   }
   
   return 0;
}

*/