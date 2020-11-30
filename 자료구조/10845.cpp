#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct node {
	int x;
	struct node *link;
}node;

typedef struct Queue {
	int queuesize;
	node *front;
	node *back;

	void Push(int x) {
		node *newnode = (node*)malloc(sizeof(node));
		newnode->x = x;
		newnode->link = NULL;
		queuesize++;

		if (front == NULL && back == NULL) {
			front = newnode;
			back = newnode;
			return;
		}

		back->link = newnode;
		back = newnode;
		return;
	}
	
	void Pop() {
		if (!queuesize) {
			cout << "-1\n";
			return;
		}

		queuesize--;
		if (front == back) back = NULL;
		cout << front->x << '\n';
		front = front->link;
		return;
	}

	void Size() {
		cout << queuesize << '\n';
	}

	void Empty() {
		if (!queuesize) cout << "1\n";
		else cout << "0\n";
	}

	void Front() {
		if (!queuesize) cout << "-1\n";
		else cout << front->x << '\n';
	}

	void Back() {
		if (!queuesize) cout << "-1\n";
		else cout << back->x << '\n';
	}
}Queue;

Queue *createnode() {
	Queue *L = (Queue*)malloc(sizeof(Queue));
	L->queuesize = 0;
	L->front = NULL;
	L->back = NULL;

	return L;
}

Queue *A;

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
		else if (!strcmp(ch, "front")) {
			A->Front();
		}
		else A->Back();
	}

	return 0;
}