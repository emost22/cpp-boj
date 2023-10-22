#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
int N, M;

void func() {
	int x;
	while (M--) {
		cin >> x;

		if (q.empty() || q.top() < x) {
			cout << "0\n";
			return;
		}

		int y = q.top();
		q.pop();
		if (y - x > 0) q.push(y - x);
	}

	cout << "1\n";
}

void input() {
	int x;
	cin >> N >> M;
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