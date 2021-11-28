#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 20
using namespace std;

int dp[MAX][1 << MAX], list[MAX][MAX];
int child[MAX];
int N, ans;

int dfs(int v, int visit) {
	int &ret = dp[v][visit];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = 0; i < N; i++) {
		if (!list[v][i]) continue;
		if ((1 << i) & visit) continue;
		
		ret = max(ret, dfs(i, visit | (1 << i)) + 1);
	}

	return ret;
}

void print(int v, int visit) {
	cout << v + 1 << ' ';
	for (int i = 0; i < N; i++) {
		if (!list[v][i]) continue;
		if ((1 << i) & visit) continue;

		if (dp[v][visit] == dp[i][visit | (1 << i)] + 1) {
			print(i, visit | (1 << i));
			return;
		}
	}
}

void func() {
	ans = dfs(0, 1);

	cout << ans << '\n';
	print(0, 1);
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}