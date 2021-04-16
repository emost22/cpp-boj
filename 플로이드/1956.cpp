#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int d[401][401];
int N, M;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int ans = d[1][1];
	for (int i = 2; i <= N; i++) {
		ans = min(ans, d[i][i]);
	}

	if (ans == INF) cout << "-1\n";
	else cout << ans << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			d[i][j] = INF;
		}
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v >> w;
		d[u][v] = w;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}