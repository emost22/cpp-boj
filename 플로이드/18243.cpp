#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int d[MAX][MAX];
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

	int net = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			net = max(net, d[i][j]);
		}
	}

	if (net > 6) cout << "Big World!\n";
	else cout << "Small World!\n";
}

void init() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (i == j) continue;

			d[i][j] = 1e9;
		}
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}