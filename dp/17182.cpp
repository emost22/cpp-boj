#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10
using namespace std;

int d[MAX][MAX], dp[MAX][1 << MAX];
int N, K, allVisit;

int dfs(int v, int visit) {
	if (visit == allVisit) return 0;

	int &ret = dp[v][visit];
	if (ret != -1) return ret;
	ret = 1e9;

	for (int i = 0; i < N; i++) {
		if (v == i) continue;

		ret = min(ret, dfs(i, visit | (1 << i)) + +d[v][i]);
	}

	return ret;
}

void func() {
	allVisit = (1 << N) - 1;

	cout << dfs(K, (1 << K)) << '\n';
}

void init() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	memset(dp, -1, sizeof(dp));
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> d[i][j];
		}
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}