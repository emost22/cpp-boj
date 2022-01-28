#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

int bfs(int sx, int sy) {
	int cnt = 1;

	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] || list[sx][sy] != list[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
			cnt++;
		}
	}

	return cnt * cnt;
}

void func() {
	int ans_w = 0;
	int ans_b = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;

			if (list[i][j] == 'W') {
				ans_w += bfs(i, j);
			}
			else {
				ans_b += bfs(i, j);
			}
		}
	}

	cout << ans_w << ' ' << ans_b << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}