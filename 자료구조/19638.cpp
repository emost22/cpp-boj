#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;
int N, H, T;

void func() {
	if (q.top() < H) {
		cout << "YES\n0\n";
		return;
	}

	for(int t = 1; t <= T; t++) {
		int x = q.top();
		q.pop();

		if (x == 1) q.push(1);
		else q.push(x >> 1);

		if (q.top() < H) {
			cout << "YES\n" << t << '\n';
			return;
		}
	}

	cout << "NO\n" << q.top() << '\n';
}

void input() {
	int x;
	cin >> N >> H >> T;
	for (int i = 0; i < N; i++) {
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