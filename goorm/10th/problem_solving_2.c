// [문제해결 10-2] 이진탐색트리 구현

/*
오늘 날짜 : 2022/12/06 
- 지난 시간 복습
이진탐색트리 
 1. 왼 < 중간 < 오
 2. 중복 허용 X
 
 ---> 시험에 나옴
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef char element;

typedef struct TreeNode { // TreeNode 구조체 생성
		char key; 
		struct TreeNode* left; 
		struct TreeNode* right; 
} TreeNode; 

TreeNode* search(TreeNode* node, int key) { // 찾는 함수
	if(node == NULL) return NULL;
	if(key == node->key) 
		return node;
	else if (key < node->key) 
		return search(node->left, key);
	else 
		return search(node->right, key);
}

TreeNode* newNode(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // 노드 동적할당
	temp->key = item;
	temp->left = temp->right = NULL; 
	return temp;
}
TreeNode* insertNode(TreeNode* node, int key){
	//탐색이 실패한 위치에 새로운 노드를 삽입 후 반환
	if ( node == NULL ) return newNode(key);
	//그렇지 않으면 순환적으로 트리를 내려간다.
	else if (key < node->key){ 
		node->left = insertNode(node->left, key);
	}
	else if (key >node->key) {
		node->right = insertNode(node->right, key);
	}
	//변경된 루트 포인터 반환
	return node;
}
TreeNode* minNode(TreeNode* node) { // 삭제하려고 하는 오른쪽 노드
	TreeNode* cur = node;
	//맨 왼쪽 최소단말 탐색
	while(cur->left !=NULL) {
		cur = cur->left;
	}
	return cur;
}

//이진 탐색트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
//새로운 루트 노드를 반환한다.

TreeNode* deleteNode(TreeNode* root, int key){
	// printf("delete 주소=%p, key =%d\n",root,key);
	if (root == NULL) return root;
	//1.만약 키가 루트보다 작으면 ->왼쪽서브트리
	if ( key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	//2.만약 키가 루트보다 크면 -> 오른쪽 서브트리
	else if(key > root->key) {
		root->right = deleteNode(root->right, key);
	} 
	//3. 키가 루트와 같으면 노드 삭제
	else {
		//3-1.삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right; // 99의 주소를 
			free(root);
			return temp;
		}
		else if (root->right == NULL){
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//3-2.삭제노드가 두개의 서브트리를 가지고 있는 경우
		TreeNode* temp = minNode(root->right); //22의 주소값
		//중위순회시 후계노드 복사
		root->key = temp->key; // 22
		//중위순회시 후계 노드 삭제
	//	printf("delete [26]주소=%p, key =%d\n",root->right,temp->key);
		root->right = deleteNode(root->right,temp->key); //26주소 ,22
	}
	return root;
}
void inorder(TreeNode* root){
	if (root != NULL){
		// 왼쪽서브트리 순회
		inorder(root->left);
		printf("%C_",root->key);//root 노드방문 출력
		// 오른쪽서브트리 순회
		inorder(root->right);
	}
}
void menu(){
	printf("\n*-----------------------*\n");
	printf("\n\t1 : 트리 출력\n");
	printf("\n\t2 : 문자 삽입\n");
	printf("\n\t3 : 문자 삭제\n");
	printf("\n\t4 : 문자 검색\n");
	printf("\n\t5 : 종료\n");
	printf("\n*-----------------------*\n");
	printf("\n메뉴 입력 >> ");

}
int main() 
{	 
	TreeNode* root = NULL;	  
	TreeNode* foundedNode = NULL; 
	char choice, key;	       

	root = insertNode(root,'G');
	insertNode(root,'I');
	insertNode(root,'H');
	insertNode(root,'D');
	insertNode(root,'B');
	insertNode(root,'M');
	insertNode(root,'N');
	insertNode(root,'A');
	insertNode(root,'J');
	insertNode(root,'E');
	insertNode(root,'Q');
	
	while( 1 ){
		menu();
		scanf(" %c", &choice);
		switch( choice - '0'){
			case 1 : printf("\t[이진 트리 출력] ");
				inorder(root);
				//탐색(출력)함수 ; printf("\n");
				break;
			case 2 : printf("삽입할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				//삽입함수 호출;
				insertNode(root, key);
				break;
			case 3 : printf("삭제할 문자를 입력하세요 : ");
				scanf(" %c", &key);
				//삭제함수 호출
				deleteNode(root, key);
				break;
			case 4 : printf("찾을 문자를 입력하세요 : ");
				scanf(" %c", &key);
				foundedNode = insertNode(root, key); // 탐색함수 호출
				if(foundedNode != NULL)
					printf("\n %c를 찾았습니다! \n", foundedNode->key);
				else printf("\n 문자를 찾지 못했습니다. \n");
				break;
			case 5 : return 0;
			default : printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
				break;
		}
	}
} 
