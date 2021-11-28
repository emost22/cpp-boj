#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int d[MAX][MAX];
int N, K, allVisit, ans;

void dfs(int v, int visit, int sum) {
	if (visit == allVisit) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) continue;

		dfs(i, visit | (1 << i), sum + d[v][i]);
	}
}

void func() {
	allVisit = (1 << N) - 1;
	ans = 1e9;

	dfs(K, (1 << K), 0);
	cout << ans << '\n';
}

void init() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
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