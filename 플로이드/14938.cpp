#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int dis[101][101], list[101];
int N, M, R;

void solve() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (dis[i][j] > M) continue;

			sum += list[j];
		}
		ans = max(ans, sum);
	}

	cout << ans << '\n';
}

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}
}

void input() {
	int u, v, w;
	cin >> N >> M >> R;
	init();
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	while (R--) {
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	solve();

	return 0;
}