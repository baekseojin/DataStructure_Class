// [문제해결 11-2] 최대힙을 이용한 정렬

#include<stdio.h>
#include<stdlib.h>

//우선순위 큐
//우선순위큐의 추상자료형
//객체: n개의 element형의 우선순위를 가진 요소들의 모임
//연산 create() :=우선순위큐 생성
//init(q), is_empty(q),is_full(q),insert(q,x) ,delete(q),find(q)
//
//우선순위큐는 0개 이상의 요소 모임
//최소순위큐 

typedef int element;
#define MAX_ELEMENT 200

typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}


void init(HeapType* h){
	h->heap_size = 0;
}


//현재 요소의 개수가 heap_size인 히프 h에 item 삽입 
void insert_max_heap(HeapType* h, element item){
    int i; // 10번째 
    i = ++(h->heap_size); // 11
    //트리를 거슬러 올라가면서 부모노드와 비교하는 과정
    while( (i!=1) && (item > h->heap[i/2]) ){
       h->heap[i] = h->heap[i/2]; // heap[11] = heap[5]
       i = i/2; // i는 올라가야 하니까
    }
    h->heap[i] = item; //새로운 노드를 삽입
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;
	
    item = h->heap[1];
	  temp = h->heap[h->heap_size]; // temp = 3
		h->heap_size--;
	
    parent = 1;
	  child = 2;
    while(child <= h->heap_size) {
       if ((child < h->heap_size) && (h->heap[child]) < (h->heap[child+1])) { //현재노드 자식 중 더 큰 자식노드를 검색
				 child++;
			 } 
       if (temp >= h->heap[child]){
				 break;
			 } 
       h->heap[parent] = h->heap[child]; //한단계 아래 이동
       parent = child;
       child *= 2; // 왼쪽 자식으로 가려면 곱하기 2
    }
    h->heap[parent] = temp;
	return item; // 9
}



//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n){
	int i;
	HeapType* h;
	h = create(); // 힙 생성 int head[200]
	h->heap_size = 0;
	for(i = 0; i < n; i++){
		//최대힙에 삽입하는 함수 호출
		insert_max_heap(h, a[i]); // 리스트를 받아서 최대힙을 만든다
	}
	for(i = n-1; i >= 0; i--){
		a[i] = delete_max_heap(h); // 최대힙 삭제
	}
	free(h);
	
} 
#define SIZE 8

int main(){
	element list[SIZE]={23,56,11,9,56,99,27,34};
	heap_sort(list,SIZE);
	for(int i =0;i<SIZE;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	return 0;
} 