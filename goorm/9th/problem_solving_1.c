// [문제해결 9-1] 배열을 이용한 이진 트리의 구현

#include<stdio.h>
// 중위순회 시험에 나옴 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 리턴조건 잘 보기

void preorder( char t[], int i, int size ) { // 전위 탐색
	if(i > size || t[i] == NULL) return ; // i가 배열의 크기보다 크거나 트리[i]의 값이 NULL이면 종료
	printf("%c ", t[i]);
	preorder(t, i*2, size); // 왼쪽 노드
	preorder(t, i*2+1, size); // 오른쪽 노드
}
void inorder( char t[], int i, int size ) { // 중위 탐색
	if(i > size || t[i] == NULL) return ; // i가 배열의 크기보다 크거나 트리[i]의 값이 NULL이면 종료
	inorder(t, i*2, size); // 왼쪽 노드
	printf("%c ", t[i]);
	inorder(t, i*2+1, size); // 오른쪽 노드
}
void postorder( char *t, int i, int size ){ // 후위 탐색
	if(i > size || t[i] == NULL) return ; // i가 배열의 크기보다 크거나 트리[i]의 값이 NULL이면 종료
	postorder(t, i*2, size); // 왼쪽 노드
	postorder(t, i*2+1, size); // 오른쪽 노드
	printf("%c ", t[i]);
}
int main(){
	char tree[]= {0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 0, 0, 'H','I',0, 'J', 'K', 'L'}; // cf) C의 부모 노드 인덱스 : 3(C의 인덱스 번호) / 2 : 1
	int size = 16;
	printf("\n<<전위 탐색>>\n");
	preorder( tree, 1, size );
	printf("\n<<중위 탐색>>\n");
	inorder( tree, 1, size );
	printf("\n<<후위 탐색>>\n");
  postorder( tree, 1, size );
	
}