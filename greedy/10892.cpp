#include <iostream>
#include <algorithm>
#define MAX 901
using namespace std;

typedef struct Node {
	int x;
	int y;
	int idx;
}Node;

Node list[MAX];
int N;

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

void func() {
	sort(list, list + N, cmp);

	for (int i = 0; i < N; i += 3) {
		cout << list[i].idx << ' ' << list[i + 1].idx << ' ' << list[i + 2].idx << '\n';
	}
}

void input() {
	cin >> N;
	N *= 3;
	for (int i = 0; i < N; i++) {
		cin >> list[i].x >> list[i].y;
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