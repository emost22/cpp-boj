#include <iostream>
#include <queue>
using namespace std;

deque<int> q;

void func() {
	while (q.size() != 1) {
		cout << q.front() << ' ';
		q.pop_front();

		q.push_back(q.front());
		q.pop_front();
	}
	cout << q.front() << '\n';
}

void input() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}