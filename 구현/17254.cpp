#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

typedef struct Node {
	int no;
	int t;
	char x;
}Node;

Node list[MAX];
int N, M;

void func() {
	sort(list, list + N, [](Node a, Node b) {
		if (a.t == b.t) return a.no < b.no;
		return a.t < b.t;
	});

	for (int i = 0; i < N; i++) {
		cout << list[i].x;
	}
	cout << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].no >> list[i].t >> list[i].x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}