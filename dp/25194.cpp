#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX][7];
int list[MAX];
int N;

int dfs(int idx, int d) {
	if (d == 5) return 1;
	if (idx == N) return 0;

	int& ret = dp[idx][d];
	if (ret != -1) return ret;
	ret = 0;

	ret |= dfs(idx + 1, (d + list[idx]) % 7);
	ret |= dfs(idx + 1, d);

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << (dfs(0, 1) ? "YES\n" : "NO\n");
}

void input() {
	cin >> N;
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