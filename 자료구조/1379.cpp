#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

typedef struct Node {
	int idx, l, r;
}Node;

Node list[MAX];
int ret[MAX];
int N;

struct cmpq {
	bool operator()(Node a, Node b) {
		return a.r > b.r;
	}
};

bool cmp(Node a, Node b) {
	return a.l < b.l;
}

void func() {
	sort(list, list + N, cmp);

	priority_queue<Node, vector<Node>, cmpq> q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!q.empty() && q.top().r <= list[i].l) {
			ret[list[i].idx] = ret[q.top().idx];
			q.pop();
		}
		else {
			ret[list[i].idx] = ++cnt;
		}
		q.push(list[i]);
	}

	cout << cnt << '\n';
	for (int i = 1; i <= N; i++) {
		cout << ret[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].idx >> list[i].l >> list[i].r;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}