// [문제해결 6-1] 배열을 이용한 선형큐 구현(1)

#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 5
typedef int element;
//Queue 구조체 정의
typedef struct {
	int front;
	int rear;
	element data[MAX_Q_SIZE];
}Queue;
void error(char* message){
	printf("%s\n",message);
	exit(0); //메인함수 종료
}
void initQueue(Queue* q){ // 큐 초기화
	q->front = -1; // 공백
	q->rear = -1; // 공백
}
int isFull(Queue* q){
	return q->rear == MAX_Q_SIZE-1; // 다 찼으면 true 출력, 아니면 false
}
int isEmpty(Queue* q) { // rear과 front가 같다
	return q->rear == q->front;
}
void enQueue(Queue* q,element item) { // 삽입 
	if(isFull(q)) {
		error("Queue is Full.\n");
	}
	q->rear++;
	q->data[q->rear] = item;
}
element deQueue(Queue* q) { // 삭제가 일어나는 순간 front가 1 증가한다.
	if(isEmpty(q)) {
		error("Queue is Empty.\n");
	}
	q->front++;
	return q->data[q->front];
}
	
void queuePrint(Queue* q){
	int i;
	for(i=0;i<MAX_Q_SIZE; i++){
		if (i<=q->front || i > q->rear){
			printf(" | ");
		}
		else{
			printf("%d | ",q->data[i]);
		}
	}
	printf("\n");
}
int main() {
	element item = 0;
	Queue q;
	initQueue(&q);
	enQueue(&q,10); queuePrint(&q);
	enQueue(&q,20); queuePrint(&q);
	enQueue(&q,30); queuePrint(&q);
	item = deQueue(&q); queuePrint(&q);
	item = deQueue(&q); queuePrint(&q);
	return 0;
}