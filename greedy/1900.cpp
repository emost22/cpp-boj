#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

typedef struct Node {
	int idx;
	int p;
	int m;
}Node;

Node list[MAX];
int N;

bool cmp(Node a, Node b) {
	return a.p + b.p * a.m > b.p + a.p * b.m;
}

void func() {
	sort(list, list + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << list[i].idx << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].p >> list[i].m;
		list[i].idx = i + 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}