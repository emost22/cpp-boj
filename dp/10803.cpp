#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 10001
#define MAX_M 101
using namespace std;

int dp[MAX_N][MAX_M];
int N, M;

int dfs(int n, int m) {
	if (!(n % m)) return n / m;
	if (n == m) return 1;

	int& ret = dp[n][m];
	if (ret != -1) return ret;
	ret = n * m;

	if (n >= 3 * m) ret = min(ret, dfs(n - m, m) + 1);
	else {
		for (int i = 1; i <= n / 2; i++) {
			ret = min(ret, dfs(i, m) + dfs(n - i, m));
		}

		for (int i = 1; i <= m / 2; i++) {
			ret = min(ret, dfs(n, i) + dfs(n, m - i));
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(N, M) << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}