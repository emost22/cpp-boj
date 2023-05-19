#include <iostream>
#include <algorithm>
#define MAX 1000
#define INF 1000000000
using namespace std;

typedef struct Node {
	int type;
	int x;
	int y;
}Node;

Node list[MAX];
int dis[MAX][MAX];
int N, T;

void init() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			dis[i][j] = INF;
			dis[j][i] = INF;
		}
	}
}

void func() {
	init();

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			dis[i][j] = dis[j][i] = abs(list[i].x - list[j].x) + abs(list[i].y - list[j].y);

			if (list[i].type && list[j].type) {
				dis[i][j] = dis[j][i] = min(dis[i][j], T);
			}
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	int M, u, v;
	cin >> M;
	while (M--) {
		cin >> u >> v;
		cout << dis[u - 1][v - 1] << '\n';
	}
}

void input() {
	cin >> N >> T;
	int type, x, y;
	for (int i = 0; i < N; i++) {
		cin >> list[i].type >> list[i].x >> list[i].y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}