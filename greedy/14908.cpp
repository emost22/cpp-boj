#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

typedef struct Node {
	int idx;
	int t;
	int s;
}Node;

Node list[MAX];
int N;

bool cmp(Node a, Node b) {
	if (a.s * b.t == b.s * a.t) return a.idx < b.idx;
	return a.s * b.t > b.s * a.t;
}

void func() {
	sort(list + 1, list + 1 + N, cmp);

	for (int i = 1; i <= N; i++) {
		cout << list[i].idx << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].t >> list[i].s;
		list[i].idx = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}