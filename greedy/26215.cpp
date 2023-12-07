#include <iostream>
#include <queue>
#define MAX 1440
using namespace std;

priority_queue<int> q;
int N;

void func() {
	for (int t = 1; t <= MAX; t++) {
		if (q.size() >= 2) {
			int x = q.top() - 1;
			q.pop();
			int y = q.top() - 1;
			q.pop();
			if (x) q.push(x);
			if (y) q.push(y);
		}
		else {
			int x = q.top() - 1;
			q.pop();
			if (x) q.push(x);
		}

		if (q.empty()) {
			cout << t << '\n';
			return;
		}
	}

	cout << "-1\n";
}

void input() {
	int x;
	cin >> N;
	while (N--) {
		cin >> x;
		q.push(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}