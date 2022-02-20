#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 101
#define MOD 10000
using namespace std;

int list[MAX];
int dp[MAX][4][4];
int N, M;

int dfs(int idx, int pre1, int pre2) {
	if (idx == N + 1) return 1;

	int& ret = dp[idx][pre1][pre2];
	if (ret != -1) return ret;
	ret = 0;

	if (list[idx]) {
		if (pre1 == pre2 && pre1 == list[idx]) return 0;
		else ret = (ret + dfs(idx + 1, list[idx], pre1)) % MOD;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (pre1 == pre2 && pre1 == i) continue;
			ret = (ret + dfs(idx + 1, i, pre1)) % MOD;
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 0, 0) << '\n';
}

void input() {
	int idx, x;
	cin >> N >> M;
	while (M--) {
		cin >> idx >> x;
		list[idx] = x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}