#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct node {
	int x;
	struct node *link;
}node;

typedef struct stacktop {
	int stacksize;
	node *top;

	void Push(int x) {
		stacksize++;
		node *newnode = (node*)malloc(sizeof(node));
		newnode->x = x;
		newnode->link = NULL;

		if (top == NULL) {
			top = newnode;
			return;
		}
		else {
			newnode->link = top;
			top = newnode;
			return;
		}
	}

	void Pop() {
		if (!stacksize) {
			cout << "-1\n";
			return;
		}
		stacksize--;

		cout << top->x << '\n';
		top = top->link;
	}

	void Size() {
		cout << stacksize << '\n';
	}

	void Empty() {
		if (!stacksize) cout << "1\n";
		else cout << "0\n";
	}

	void Top() {
		if (!stacksize) cout << "-1\n";
		else cout << top->x << '\n';
	}
}stacktop;

stacktop *createnode() {
	stacktop *L = (stacktop*)malloc(sizeof(stacktop));
	L->stacksize = 0;
	L->top = NULL;
	
	return L;
}

stacktop *A;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	char ch[6];
	int N;
	cin >> N;
	A = createnode();
	while (N--) {
		cin >> ch;

		if (!strcmp(ch, "push")) {
			int x;
			cin >> x;
			A->Push(x);
		}
		else if (!strcmp(ch, "pop")) {
			A->Pop();
		}
		else if (!strcmp(ch, "size")) {
			A->Size();
		}
		else if (!strcmp(ch, "empty")) {
			A->Empty();
		}
		else {
			A->Top();
		}
	}

	return 0;
}