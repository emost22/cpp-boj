#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct queue {
	int x;
	struct queue *link;
	struct queue *parent;
}Q;

typedef struct head {
	int size;
	Q *front;
	Q *back;

	struct head *create() {
		head *L = (head*)malloc(sizeof(head));
		L->size = 0;
		L->front = NULL;
		L->back = NULL;

		return L;
	}
	void Push(int x) {
		size++;
		Q *newnode = (Q*)malloc(sizeof(Q));
		newnode->x = x;
		newnode->link = NULL;
		newnode->parent = NULL;

		if (front == NULL) {
			front = newnode;
			back = newnode;
		}
		else {
			newnode->parent = back;
			back->link = newnode;
			back = newnode;
		}
	}
	void Pop() {
		if (front == NULL && back == NULL) {
			cout << "-1\n";
			return;
		}
		size--;
		cout << front->x << '\n';
		if (front == back) {
			front = NULL;
			back = NULL;
			return;
		}
		front->link->parent = NULL;
		front = front->link;
	}
	void Size() {
		cout << size << '\n';
	}
	void Empty() {
		if (size == 0) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
	void Front() {
		if (!size) cout << "-1\n";
		else cout << front->x << '\n';
	}
	void Back() {
		if (!size) cout << "-1\n";
		else cout << back->x << '\n';
	}
}head;

head *A;
int N;
string str;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	A = A->create();
	int x;
	cin >> N;
	while (N--) {
		cin >> str;
		if (!str.compare("push")) {
			cin >> x;
			A->Push(x);
		}
		else if (!str.compare("pop")) {
			A->Pop();
		}
		else if (!str.compare("size")) {
			A->Size();
		}
		else if (!str.compare("empty")) {
			A->Empty();
		}
		else if (!str.compare("front")) {
			A->Front();
		}
		else if (!str.compare("back")) {
			A->Back();
		}
	}

	return 0;
}