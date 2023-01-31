// [실습과제 7-3] ArrayList

#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // 리스트의 최대크기

typedef int element;
//배열리스트 구조체타입 정의
typedef struct {
	element array[MAX];
	int size;
}ArrayList;

void init(ArrayList* L){ // 배열리스트 초기화
  L->size = 0;
}

int isEmpty(ArrayList* L){
	return L->size == 0;
}

int isFull(ArrayList* L){
	return L->size == MAX; 
}

element getEntry(ArrayList* L, int pos){
 	if(pos < 0 || pos>= L->size) {
		error("위치 오류");
	}
	return L->array[pos];
}

void printList(ArrayList* L){
	int i;
	for(i=0; i<L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

void insertLast(ArrayList* L, element item){
	if(L->size >= MAX) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayList* L, int pos, element item){
	if(!isFull(L) && (pos>=0) && (pos <= L->size) ) {
		for(int i = (L->size-1); i>=pos; i--) {
			L->array[i+1] = L->array[i]; 
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delete(ArrayList* L,int pos){
	element item;
	if(pos<0 || pos>=L->size) {
		error("위치 오류");	
	}
	item = L->array[pos];
	for(int i = pos; i<(L->size-1); i++) {
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}

int main(){
	ArrayList list;
	init(&list);
	insert(&list, 0, 10);
	printList(&list);
	insert(&list, 1, 20);
	printList(&list);
	insert(&list, 2, 30);
	printList(&list);
	insert(&list, 3, 40);
	printList(&list);
	insert(&list, 2, 100);
	printList(&list);
	delete(&list, 1);
	printList(&list);
	return 0;
}