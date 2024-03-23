#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N;

void init() {
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
}

void func() {
	while (q.size() > 1) {
		int cnt = 0;
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			cnt++;
			if (cnt & 1) continue;
			q.push(x);
		}
	}

	cout << q.front() << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}