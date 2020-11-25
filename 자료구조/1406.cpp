#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct node {
	char x;
	struct node *child;
	struct node *parent;
}node;

node *createnode(char x) {
	node *L = (node*)malloc(sizeof(node));
	L->x = x;
	L->child = NULL;
	L->parent = NULL;

	return L;
}

node *A;
node *idx;
string str;
int M;

void addnodeinit(char x) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->x = x;
	newnode->child = NULL;

	idx->child = newnode;
	newnode->parent = idx;
	idx = idx->child;
}

void addnode(node *p, char x) {
	node *newnode = (node*)malloc(sizeof(node));
	newnode->x = x;
	idx = newnode;

	if (p->child == NULL) {
		newnode->child = p->child;
		newnode->parent = p;
		p->child = newnode;
		return;
	}
	else {
		newnode->child = p->child;
		newnode->parent = p;
		p->child->parent = newnode;
		p->child = newnode;
		return;
	}
}

void delnode(node *d) {
	if (d->child == NULL) {
		idx = d->parent;
		d->parent->child = NULL;
		free(d);
		return;
	}
	else {
		idx = d->parent;
		d->child->parent = d->parent;
		d->parent->child = d->child;
		free(d);
		return;
	}
}

void input() {
	char re;
	cin >> str >> M;
	A = createnode(' ');
	idx = A;
	for (int i = 0; i < str.size(); i++) {
		addnodeinit(str[i]);
	}

	while (M--) {
		cin >> re;
		if (re == 'L') {
			if (idx->parent == NULL) continue;
			else idx = idx->parent;
		}
		else if (re == 'D') {
			if (idx->child == NULL) continue;
			else idx = idx->child;
		}
		else if (re == 'B') {
			if (idx->parent == NULL) continue;
			else delnode(idx);
		}
		else {
			char x;
			cin >> x;
			addnode(idx, x);
		}
	}
}

void print() {
	node *ans = A->child;
	while (ans != NULL) {
		cout << ans->x;
		ans = ans->child;
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}