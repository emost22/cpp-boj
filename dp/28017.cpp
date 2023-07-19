#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 501
using namespace std;

int list[MAX][MAX], dp[MAX][MAX];
int N, M;

int dfs(int idx, int pre) {
	if (idx > N) return 0;

	int& ret = dp[idx][pre];
	if (ret != -1) return ret;

	for (int i = 1; i <= M; i++) {
		if (pre == i) continue;

		if (ret == -1) ret = dfs(idx + 1, i) + list[idx][i];
		else ret = min(ret, dfs(idx + 1, i) + list[idx][i]);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 0) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}