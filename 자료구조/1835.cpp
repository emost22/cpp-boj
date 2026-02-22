#include <iostream>
#include <deque>
using namespace std;

deque<int> q;
int N;

void func() {
	for (int i = N; i >= 1; i--) {
		q.push_front(i);
		int m = i % q.size();
		for (int j = 0; j < m; j++) {
			q.push_front(q.back());
			q.pop_back();
		}
	}

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop_front();
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}