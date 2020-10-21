#include <iostream>
#define INF 1000000000
using namespace std;

int N, M;
int graph[101][101];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) graph[i][j] = INF;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v, w;
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		if (graph[u][v] > w) graph[u][v] = w;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (graph[j][i] + graph[i][k] < graph[j][k]) {
					graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] != INF) cout << graph[i][j] << ' ';
			else cout << "0 ";
		}
		cout << '\n';
	}

	return 0;
}