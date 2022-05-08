#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 3001
#define MOD 1000000009
using namespace std;

char list[MAX][MAX];
int dp[MAX][MAX];
int N, M;

int dfs(int x, int y) {
	if (list[x][y] == 'X') return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	if (list[x][y] == 'B') {
		if (x + 1 < N) ret = (ret + dfs(x + 1, y)) % MOD;
		if (y + 1 < M) ret = (ret + dfs(x, y + 1)) % MOD;
	}
	else if (list[x][y] == 'E') {
		if (y + 1 < M) ret = (ret + dfs(x, y + 1)) % MOD;
	}
	else {
		if (x + 1 < N) ret = (ret + dfs(x + 1, y)) % MOD;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = (ans + dfs(i, j)) % MOD;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
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