// [실습과제 9-1] 이진트리의 구현과 순회

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {	
	// 멤버변수 작성
	int data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode* makeRootNode(char data, TreeNode* leftNode, TreeNode* rightNode){
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode)); // 트리 노드 동적할당 
	root->data = data; // 데이터
	root->left = leftNode; // 왼쪽노드 주소값
	root->right = rightNode; // 오른쪽 주소값
	return root; // 생성된 노드의 주소
}

preorder(TreeNode* root){
	if(root != NULL) {
		printf("[%d] ", root->data); // 노드 방문
		preorder(root->left); // 왼쪽 서브트리 방문
		preorder(root->right); // 오른쪽 서브트리 방문
	}
}

inorder(TreeNode* root)
{
	if(root!=NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

postorder(TreeNode* root) {
	if(root!=NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(){
	TreeNode* n1 = makeRootNode(1, NULL, NULL);
	TreeNode* n2 = makeRootNode(4, n1, NULL);
	TreeNode* n3 = makeRootNode(16, NULL, NULL);
	TreeNode* n4 = makeRootNode(25, NULL, NULL);
	TreeNode* n5 = makeRootNode(20, n3, n4);
	TreeNode* n6 = makeRootNode(15, n2, n5);
	TreeNode* root = n6; // root 노드 주소값 저장
	
	printf("중위 순회=");
	inorder(root);
	printf("\n");
	printf("전위 순회=");
	preorder(root);
	printf("\n");
	printf("후위 순회=");
	postorder(root);
	printf("\n");

	//동적할당 해제 함수 호출
	free(root);
	return 0;
}
