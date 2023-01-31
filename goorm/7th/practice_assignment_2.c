// [실습과제 7-2] 연결리스트의 합

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {    // 노드 타입
   element data;
   struct Node *next;
} Node;

Node* insertFirst(Node *head, int value)
{
  Node* newNode = (Node*)malloc(sizeof(Node)); //(1) 노드 동적할당
   newNode->data = value;   // (2) 값저장
   newNode->next = head; // 헤드 포인터의 값을 복사   //(3)
   head = newNode;// 헤드 포인터 변경      //(4)
   return head; // 변경된 헤드 포인터 반환
}

Node* insert(Node* head, Node* pre, element value)
{

}

Node* deleteFirst(Node *head)
{

}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
Node* delete(Node *head, Node *pre)
{
   
}

void printList(Node *head)
{

}

int getSum(Node *head)
{
   int sum = 0;
   Node* p = (Node*)malloc(sizeof(Node)); // 합을 더할 노드를 차례로 가리킬 노드 포인터 변수 p
   p = head; // p가 첫 번째 노드부터 가리킴
   
   //노드의 데이터를 더하는 코드 작성
   while(p != NULL){ // p가 가리키는 노드가 있는 동안
      sum += p->data; // sum에 p가 가리키는 노드의 data 저장하기
      p = p->next; // p가 다음 노드를 가리키기
   }
   
   // for(Node* p = head; p != NULL; p = p->next){
   //    sum = sum + p->data;
   // }
   
   return sum; // 리스트 데이터의 합 반환
}


int main(void)
{
   Node* head = NULL; // NULL로 초기화
   int count, data;
   
   printf("노드의 개수: ");
   scanf("%d", &count); // 합을 더할 노드의 개수 입력받기
   
   Node* p = (Node* )malloc(sizeof(Node)); // 노드를 차례차례 가리킬 노드 포인터 변수
   p = head; // p는 첫 번째 노드(= head가 가리키는 노드)부터 가리킴, head의 값을 p의 값으로 넣기
   
   for (int i = 1; i <= count; i++) {
      printf("노드 #%d 데이터: ", i);
      scanf("%d", &data);
      head = insertFirst(head, data); // insertFirst()로 변경된 head 포인터의 값을 head에 저장
   }
   
   printf("연결 리스트 데이터의 합 : %d ", getSum(head));
   return 0;
}