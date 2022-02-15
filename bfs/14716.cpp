#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 250
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
int N, M;

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j] || visit[i][j]) continue;

			ans++;
			bfs(i, j);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
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