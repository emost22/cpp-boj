#include <iostream>
using namespace std;

int N;

bool prime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (!(x % i)) return false;
	}

	return true;
}

void dfs(int cnt, int x) {
	if (cnt == N) {
		cout << x << '\n';
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		int next = x * 10 + i;
		if (!prime(next)) continue;
		dfs(cnt + 1, next);
	}
}

void func() {
	dfs(1, 2);
	dfs(1, 3);
	dfs(1, 5);
	dfs(1, 7);
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