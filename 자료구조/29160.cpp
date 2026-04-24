#include <iostream>
#include <queue>
#define MAX 11
using namespace std;

priority_queue<int> q[MAX + 1];
int N, K;

void func() {
	while (K--) {
		for (int i = 1; i <= MAX; i++) {
			if (q[i].empty()) continue;

			int x = q[i].top();
			q[i].pop();
			q[i].push(max(0, x - 1));
		}
	}

	int ret = 0;
	for (int i = 1; i <= MAX; i++) {
		if (q[i].empty()) continue;
		ret += q[i].top();
	}

	cout << ret << '\n';
}

void input() {
	int pos, w;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> pos >> w;
		q[pos].push(w);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}