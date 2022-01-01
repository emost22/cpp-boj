#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 10000
#define MAX_M 501
using namespace std;

int dp[MAX_N][MAX_M];
int list[MAX_N];
int N, M;

int dfs(int idx, int now) {
	if (idx > N) {
		if (!now) return 0;
		else return -1e9;
	}
	if (idx > N - now) return -1e9;

	int& ret = dp[idx][now];
	if (ret != -1) return ret;
	ret = 0;

	if (now < M) {
		if (now) {
			ret = max(dfs(idx + 1, now + 1) + list[idx], dfs(idx + now, 0));
		}
		else {
			ret = max(dfs(idx + 1, now + 1) + list[idx], dfs(idx + 1, 0));
		}
	}
	else {
		ret = dfs(idx + M, 0);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';
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