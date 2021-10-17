#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		int x = -q.top();
		q.pop();
		int y = -q.top();
		q.pop();

		ans += (x * y);
		q.push(-(x + y));
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push(-x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}