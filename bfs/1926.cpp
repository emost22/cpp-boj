#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, artnum, maxarea;
int list[500][500], direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
bool visit[500][500];

int bfs(int sx, int sy) {
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}

	return cnt;
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j] || visit[i][j]) continue;

			artnum++;
			maxarea = max(maxarea, bfs(i, j));
		}
	}

	cout << artnum << '\n' << maxarea << '\n';
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