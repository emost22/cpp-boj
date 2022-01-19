#include <iostream>
#include <algorithm>
#define MAX 251
using namespace std;

int d[MAX][MAX];
int N, M, K;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int u, v;
	cin >> K;
	while (K--) {
		cin >> u >> v;
		cout << d[u][v] << '\n';
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			d[i][j] = 1e9;
		}
	}
}

void input() {
	int u, v, t;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v >> t;
		
		d[u][v] = 0;

		if (t) d[v][u] = 0;
		else d[v][u] = 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}