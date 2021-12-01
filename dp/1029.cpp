#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 15
using namespace std;

int list[MAX][MAX];
int dp[MAX][1 << MAX][10];
int N;

int dfs(int v, int visit, int now) {
	int &ret = dp[v][visit][now];
	if (ret != -1) return ret;
	ret = 1;

	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) continue;
		if (now > list[v][i]) continue;

		ret = max(ret, dfs(i, visit | (1 << i), list[v][i]) + 1);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1, 0) << '\n';
}

void input() {
	char ch;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			list[i][j] = ch - '0';
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