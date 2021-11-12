#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

priority_queue<int> q;
int N, x;

void func() {
	if (N == 1) {
		cout << "0\n";
		return;
	}

	for (int ans = 0; ; ans++) {
		int y = q.top();
		q.pop();

		if (x > y) {
			cout << ans << '\n';
			return;
		}

		q.push(y - 1);
		x++;
	}
}

void input() {
	int y;
	cin >> N >> x;
	for (int i = 1; i < N; i++) {
		cin >> y;
		q.push(y);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}