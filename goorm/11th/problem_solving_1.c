// [문제해결 11-1] 우선순위큐 힙트리의 구현

/*
힙트리 특징
- 완전이진트리
- 중복 허용
- 부모키 >= 자식키
- 계층별 정렬
- 최대힙 : 부모 >= 자식
- 최소힙 : 부모 <= 자식
- 배열로 표현 가능
*/

#include <stdio.h>
#include<stdlib.h>

#define MAX 200
typedef int element;

typedef struct Hypetype {
	// 힙트리 구조체 정의
	int heap[MAX];
	int heap_size;
} HeapType;

//현재 요소의 개수가 heap_size인 히프 h에 item 삽입 
void insertMaxHeap(HeapType* h, element item) { // item = 8
	int i; // i == 10
	i = ++(h->heap_size); // 새로운 노드가 들어올 것이기 때문에 1칸 늘려줌, i == 11
	while( (i!=1) && (item > h->heap[i/2]) ){//삽입노드가 부모보다 크면
		h->heap[i] = h->heap[i/2]; // 부모노드를 삽입위치로 교환, 4가 8로 감( heap[11] = heap[5] ) 
		i = i/2; // i는 부모노드 위치
	}
	h->heap[i] = item; // head[2] = 8 새로운 노드 삽입
}
element deleteMaxHeap(HeapType* h){ 
	int parent, child;
	element item, temp;
	item = h->heap[1];//루트노드 반환값
	temp = h->heap[h->heap_size]; //말단노드를 저장
	h->heap_size--;
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		//현재 노드의 자식 노드 중 더 큰 자식 노드를 검색
		if (child < h->heap_size && h->heap[child] < h->heap[child+1]/*오른쪽노드*/ )
			child++;
		//검색된 자식노드가 말단노드이면 아래로 이동안함.	
		if (temp >= h->heap[child] ) break; 
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];//
		parent = child; // 
		child *= 2;
	}
	h->heap[parent] = temp; //
	return item;
}

void printHeap(HeapType* heap){
	for(int i = 1;i<=heap->heap_size;i++)
		printf("[%d]: %d ",i, heap->heap[i]);
	printf("\n");
}

int main(){
	element e1 =10,e2=5,e3=30;
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType)); //동적할당;
	heap->heap_size = 0;
	//삽입
	printf("최대힙 삽입\n");
	insertMaxHeap(heap,e1);	printHeap(heap);
	insertMaxHeap(heap,e2);	printHeap(heap);
	insertMaxHeap(heap,e3);	printHeap(heap);

	//삭제
	printf("최대힙 삭제\n");
	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	free(heap);
	return 0;
}