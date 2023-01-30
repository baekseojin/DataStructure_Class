// [문제해결 6-3] 배열을 이용한 원형 큐의 구현

#include<stdlib.h>
#include <stdio.h>
#define MAX_Q_SIZE 5

typedef int element;
typedef struct{
	int rear;
	int front;
	element data[MAX_Q_SIZE];
}Queue;

void initQueue(Queue* q){
	//front, rear 초기화
	q->front = 0;
	q->rear = 0;
}

int isEmpty(Queue* q){
	return (q->rear == q->front);	 
}

int isFull(Queue* q){
	return (q->rear+1) % MAX_Q_SIZE == q->front;
}

void enQueue(Queue* q, element item){
	if (isFull(q)) printf("큐가 포화상태입니다.\n"); 
	else{
		q->rear = (q->rear + 1) % MAX_Q_SIZE; // q->rear = 1
		q->data[q->rear] = item; // data[1] = 입력받은 정수
	}
}

element deQueue(Queue* q){
	if(isEmpty(q)) printf("큐는 공백상태입니다.\n");
	else{
		q->front = (q->front+1) % MAX_Q_SIZE;
		return q->data[q->front];
	}
}

void printQueue(Queue* q){
	int i;
	printf("QUEUE(front=%d rear=%d) = ",q->front, q->rear); 
	if (isEmpty(q)) {
		printf("큐는 공백상태입니다.\n");
		return;
	}
	 i = q->front; // 데이터 시작하는 앞의 자리
	do{
		i = (i+1)% (MAX_Q_SIZE);
		printf("%d | ",q->data[i]);
		if(i == q->rear) break;
	}while(i!=q->front);
	printf("\n");
}

int main() {
	Queue q;
	element item; // int item;
	initQueue(&q); // q->front=0;  q->rear=0;
	printf("--데이터 추가 단계--\n"); 
	while (!isFull(&q)){ // 포화 상태가 아닐 때 실행
		printf("정수를 입력하시오."); 
		scanf("%d",&item); 
		enQueue(&q,item); // 입력받은 정수를 큐에 추가
		printQueue(&q); // 
	}
	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");
	while(!isEmpty(&q)){
		item = deQueue(&q);
		printf("꺼내진 정수 : %d\n",item);
		printQueue(&q);
	}
	
	return 0;
}
