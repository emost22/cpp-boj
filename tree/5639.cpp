#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

typedef struct treenode {
	int value;
	struct treenode *llink;
	struct treenode *rlink;
}treenode;

void addnode(treenode *L, int x) {
	treenode *newnode, *p;
	newnode = (treenode*)malloc(sizeof(treenode));
	newnode->value = x;
	newnode->llink = NULL;
	newnode->rlink = NULL;

	p = L;

	while (1) {
		if (p->value > x) {
			if (p->llink == NULL) {
				p->llink = newnode;
				break;
			}
			p = p->llink;
		}
		else {
			if (p->rlink == NULL) {
				p->rlink = newnode;
				break;
			}
			p = p->rlink;
		}
	}

}

void postorder(treenode *L) {
	if (L->llink != NULL) postorder(L->llink);
	if (L->rlink != NULL) postorder(L->rlink);
	printf("%d\n", L->value);
}

int main() {
	int a;
	treenode *A;
	A = (treenode*)malloc(sizeof(treenode));
	A->llink = NULL;
	A->rlink = NULL;
	
	cin >> a;
	A->value = a;

	while (scanf("%d", &a) != EOF) {
		addnode(A, a);
	}

	postorder(A);

	return 0;
}