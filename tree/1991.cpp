#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct treenode {
	char data;
	struct treenode *llink;
	struct treenode *rlink;
}treenode;

treenode *createnode() {
	treenode *L;
	L = (treenode*)malloc(sizeof(treenode));
	L->data = 'A';
	L->llink = NULL;
	L->rlink = NULL;

	return L;
}

void addnode(treenode *L, char parent, char data, int check) {
	if (L->data == parent) {
		treenode *newnode;
		newnode = (treenode*)malloc(sizeof(treenode));
		newnode->data = data;
		newnode->llink = NULL;
		newnode->rlink = NULL;

		if (!check) {
			L->llink = newnode;
			return;
		}
		else {
			L->rlink = newnode;
			return;
		}
	}
	else {
		if (L->llink != NULL) addnode(L->llink, parent, data, check);
		if (L->rlink != NULL) addnode(L->rlink, parent, data, check);
	}
}

void preorder(treenode *L) {
	cout << L->data;
	if (L->llink != NULL) preorder(L->llink);
	if (L->rlink != NULL) preorder(L->rlink);
}

void inorder(treenode *L) {
	if (L->llink != NULL) inorder(L->llink);
	cout << L->data;
	if (L->rlink != NULL) inorder(L->rlink);
}

void postorder(treenode *L) {
	if (L->llink != NULL) postorder(L->llink);
	if (L->rlink != NULL) postorder(L->rlink);
	cout << L->data;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	treenode *A;

	A = createnode();

	int N;
	char parent, data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		for (int j = 0; j < 2; j++) {
			cin >> data;
			if (data != '.') addnode(A, parent, data, j);
		}
	}
	
	preorder(A);
	cout << '\n';
	inorder(A);
	cout << '\n';
	postorder(A);
	cout << '\n';

	return 0;
}