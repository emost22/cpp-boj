#include <iostream>
#include <algorithm>
#define MAX 201
using namespace std;

int dis[MAX][MAX];
int N, M;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	int idx = 0;
	int ret = 1e9;
	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			sum += dis[i][j];
		}

		if (ret > sum) {
			ret = sum;
			idx = i;
		}
	}

	cout << idx << '\n';
}

void init() {
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			dis[i][j] = dis[j][i] = 1e9;
		}
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;

	init();
	while (M--) {
		cin >> u >> v >> w;

		dis[u][v] = dis[v][u] = w;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}