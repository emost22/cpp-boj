#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int list[MAX];
int N, L, R, X, ans;

void dfs(int idx, int l, int r, int sum) {
	if (sum > R) return;
	if (idx == N) {
		if (sum < L || r - l < X) return;
		ans++;
		return;
	}

	dfs(idx + 1, min(l, list[idx]), max(r, list[idx]), sum + list[idx]);
	dfs(idx + 1, l, r, sum);
}

void func() {
	dfs(0, 1e9, 0, 0);
	cout << ans << '\n';
}

void input() {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}