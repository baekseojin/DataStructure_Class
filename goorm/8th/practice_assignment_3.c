// [실습과제 8-3] 원형연결리스트 이용 순열

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}DlistNode;

void init(DlistNode *phead) {
	phead->llink=phead;
	phead->rlink=phead;
}

void dinsert_node(DlistNode *before, DlistNode *new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink=new_node;
}
void dremove_node(DlistNode *phead_node, DlistNode *removed) {
	if (removed == phead_node) return;
	removed->llink->rlink=removed->rlink;
	removed->rlink->llink=removed->llink;
	free(removed);
}
int main(void) {
	int n,m;
	scanf("%d %d", &n,&m);
	DlistNode head_node;
	DlistNode *p[n];
	DlistNode *o;
	init(&head_node);
	int i,j; 
	for(i=n;i>0;i--) {
		p[i] = (DlistNode *)malloc(sizeof(DlistNode));
		p[i]->data = i;
		dinsert_node(&head_node, p[i]);
	}
	
	printf("<");
	o=&head_node;
	
	while(o->rlink != &head_node || o->llink != &head_node ) {
		for(j=0;j<m;j++) {
			o=o->rlink;
			if(o==&head_node)
				o=o->rlink;
		}
		printf("%d, ",o->data);
		o=o->rlink;
		dremove_node(&head_node,o->llink);
		if(o->rlink == &head_node && o->llink == &head_node) break;
		o=o->llink;
	}
	if(o->data != NULL && o->data<n)
		printf("%d",o->data);
		dremove_node(&head_node,o);
	
	printf(">");	
	return 0;
}