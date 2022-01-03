#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 51
#define MOD 1000007
using namespace std;

int dp[MAX][MAX][MAX][MAX];
int list[MAX][MAX];
int N, M, K;

int dfs(int x, int y, int k, int pre) {
	if (x > N || y > M) return 0;

	if (x == N && y == M) {
		if (k == 1 && list[x][y] > pre) return 1;
		if (!k && !list[x][y]) return 1;
		return 0;
	}

	int &ret = dp[x][y][k][pre];
	if (ret != -1) return ret;
	ret = 0;

	if (!list[x][y]) {
		ret = (dfs(x + 1, y, k, pre) + dfs(x, y + 1, k, pre)) % MOD;
	}
	else if (list[x][y] > pre) {
		ret = (dfs(x + 1, y, k - 1, list[x][y]) + dfs(x, y + 1, k - 1, list[x][y])) % MOD;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= K; i++) {
		cout << dfs(1, 1, i, 0) << ' ';
	}
	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		cin >> x >> y;
		list[x][y] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}