// [문제해결 10-1] 이진탐색트리(탐색 및 삽입)

////////////////////////// 시험 !!!!!!!!!!!!!!!!!!!!!!!1
/* review(복습)
트리는 왼쪽이 NULL값일 때 까지 탐색

중위순회 : 산모양
왼쪽 - 루트 - 오른쪽
왼쪽값이 NULL일 때까지 내려가서 왼쪽을 다 찍으면 루트

*/

/*
이진탐색트리 탐색 : 반가르기
이진탐색트리 삽입 : 탐색에 실패한 위치가 삽입 위치
이진탐색트리 삭제 : 1. 삭제노드가 단말노드 -> 단말노드의 부모노드를 찾아 연결을 끊는다. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode{
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

// 순환적 탐색함수
TreeNode* search(TreeNode* node, int key){
	if(node == NULL ) return NULL;
	if(key == node->key) 
		return node; // 같으면(탐색성공) 노드의 주소 반환
	
	else if (key < node->key) 
		return search(node->left, key); // 내가 찾으려는 값(key)이 탐색값보다 작으면 left로 간다
	
	else return search(node->right, key); // 내가 찾으려는 값(key)이 탐색값보다 크면 right로 감
}

TreeNode* newNode(int item) { // 새로운 노드 생성
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // 노드 동적할당
	temp->key = item; //
	temp->left = temp->right = NULL; 
	return temp;
}

TreeNode* insertNode(TreeNode* node, int key){
	//탐색이 실패한 위치에 새로운 노드를 삽입 후 반환
	if ( node == NULL ) return newNode(key); // 새 노드를 만든다(탐색이 실패한 위치에 새로운 노드 )
	//그렇지 않으면 순환적으로 트리를 내려간다.
	else if (key < node->key) { // 내가 삽입하려는 값이 탐색값보다 작으면  
		node->left = insertNode(node->left, key); 
	}
	else if (key > node->key) {
		node->right = insertNode(node->right, key); 
	}
	//변경된 루트 포인터 반환
	return node;
}

TreeNode* minNode(TreeNode* node) { // node = 26
	TreeNode* cur = node; // cur = 26
	//맨 왼쪽 최소단말 탐색
	while(cur->left != NULL) { // cur->left = 22가 NULL이 아니니까
		cur = cur->left; // cur = 22
	}
	return cur; // 22 반환
}

//이진 탐색트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
//새로운 루트 노드를 반환한다.
TreeNode* deleteNode(TreeNode* root, int key) { // root = 35, key = 18
	
	if (root == NULL) return root;
	
	// 1.만약 키가 루트보다 작으면 -> 왼쪽서브트리
	if ( key < root->key) {
		root->left = deleteNode(root->left, key); // root = 18, key = 18
	}
	
	//2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
	else if(key > root->key) {
		root->right = deleteNode(root->right, key);	
	} 
	
	//3. 키가 루트와 같으면 노드 삭제
	else if(key == root->key) {
		// 3-1.삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
		if (root->left == NULL) { // key : 68
			TreeNode* temp = root->right;
			free(root);
			return temp; 
		}
		else if (root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//3-2.삭제노드가 두개의 서브트리를 가지고 있는 경우
		TreeNode* temp = minNode(root->right);  // temp = minNode(26) = 22
		
		// 중위순회시 후계노드 복사
		root->key = temp->key; // root->key(18) = 22
		
		// 중위순회시 후계 노드 삭제
		root->right = deleteNode(root->right,temp->key); // deleteNode(26, 22)
	}
	return root;
}

void inorder(TreeNode* root){
	if (root != NULL){
		// 왼쪽 서브트리 순회
		inorder(root->left);
		//root 노드방문 출력
		printf("[%d] ",root->key);
		///오른쪽 서브트리 순회
		inorder(root->right);
	}
}

int main() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	int n;
	root = insertNode(root,35);
	root = insertNode(root,18);
	root = insertNode(root,68);
	root = insertNode(root,7);
	root = insertNode(root,26);
	root = insertNode(root,99);
	root = insertNode(root,3);
	root = insertNode(root,12);
	root = insertNode(root,22);
	root = insertNode(root,30);
	
  printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	printf("\n삭제할 숫자를 입력하세요\n");
	scanf("%d",&n);
	deleteNode(root,n); // deleteNode(35, 18)
	printf("이진탐색트리 중위순회 결과 출력\n");
	inorder(root);
	
	return 0;
}

/*
TreeNode* deleteNode(TreeNode* root, int key) { // root = 26, key = 22
	
	if (root == NULL) return root; // NULL을 반환, 22 제거
	
	// 1.만약 키가 루트보다 작으면 -> 왼쪽서브트리
	if ( key < root->key) {
		root->left = deleteNode(root->left, key); // root = NULL, key = 18
	}
	
	//2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
	else if(key > root->key) {
		root->right = deleteNode(root->right, key);	
	} 
	
	//3. 키가 루트와 같으면 노드 삭제
	else if(key == root->key) {
		// 3-1.삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
		if (root->left == NULL) { // key : 68
			TreeNode* temp = root->right;
			free(root);
			return temp; 
		}
		else if (root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//3-2.삭제노드가 두개의 서브트리를 가지고 있는 경우
		TreeNode* temp = minNode(root->right);  // temp = minNode(26) = 22
		
		// 중위순회시 후계노드 복사
		root->key = temp->key; // root->key(18) = 22
		
		// 중위순회시 후계 노드 삭제
		root->right = deleteNode(root->right,temp->key); // deleteNode(26, 22)
	}
	return root;
}
*/
