// [문제해결 9-2] 연결리스트를 이용한 트리의 구현


/*
시험문제 : "실제로 탐색한 결과를 고르세요." 이렇게 나옴
중위순회가 시험문제 나옴

전위순회(루트를 제일 첫 번째) : 루트 - 왼쪽 - 오른쪽
	- 왼쪽에 있는 서브트리를 다 실행해야 오른쪽 서브트리로 간다.
	->  - * A B / C D
중위 순회(루트를 중간번째) : 왼쪽 - 루트 - 오른쪽'
후위(루트를 제일 마지막 번째): 왼쩍 - 오른쪽 - 루트
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

/*     -
     /   \
    *     /
   / \   / \ 
  A   B  C  D     */


TreeNode* makeRootNode(char data, TreeNode* leftNode, TreeNode* rightNode)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode)); // 루트 노드 동적할당
	root->data = data; // 루트의 데이터에 데이터를 넣는다
	root->left = leftNode; // 루트의 왼쪽에 왼쪽 루트를 넣는다
	root->right = rightNode; // 루트의 오른쪽에 오른쪽 루트를 넣는다
	return root;
}

void preorder(TreeNode* root)
{
	if(root!=NULL) {
		printf("%c", root->data); // 전위순회 : 루트 -> 왼쪽 -> 오른쪽, left가 NULL일 떄 까지 탐색
		preorder(root->left); 
		preorder(root->right);
	}
	
	
}

void inorder(TreeNode* root)
{
	if(root!=NULL) {
		inorder(root->left); // 왼쪽까지 먼저 간다
		printf("%c", root->data); // 중위순회 : 왼쪽 -> 루트 -> 오른쪽, 왼쪽부터 차례대로 출력  
		inorder(root->right);
	}
	
	
}

void postorder(TreeNode* root)
{
	if(root!=NULL) {
		postorder(root->left); // 왼쪽 먼저
		postorder(root->right); // 왼쪽 다 탐색하고 오른쪽
		printf("%c", root->data); // 후위순회 : 왼쪽 -> 오른쪽 -> 루트, 왼쪽부터 차례대로 출력  
	}
	
	
}

void main()
{
	TreeNode* n7 = makeRootNode('D', NULL, NULL); // 자식의 인수를 NULL로 만듦
	TreeNode* n6 = makeRootNode('C', NULL, NULL);
	TreeNode* n5 = makeRootNode('B', NULL, NULL);
	TreeNode* n4 = makeRootNode('A', NULL, NULL);
	TreeNode* n3 = makeRootNode('/', n6, n7); // n3(/)의 자식 : n6(C), n7(D)
	TreeNode* n2 = makeRootNode('*', n4, n5); // n2(*)의 자식 : n4(A), n5(B)
	TreeNode* n1 = makeRootNode('-', n2, n3); // n1(-)의 자식 : n2(*), n3(/)

	printf("\n preorder  : ");
	preorder(n1);
	
	printf("\n inorder   : ");
	inorder(n1);
	
	printf("\n postorder : ");
	postorder(n1);
	free(n1);free(n2);free(n3);
	free(n4);free(n5);free(n6);
	free(n7);
	
}