#include <iostream>
#include <queue>
using namespace std;

typedef struct st {
	int x;
	int y;
	int cnt;
	int wall;
}st;

int N, M, K;
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
char list[1010][1010];
bool visit[1010][1010][11];

void bfs() {
	queue<st> q;
	q.push({ 0, 0, 1, 0 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int wall = q.front().wall;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] == '1') {
				if (wall + 1 > K) continue;
				if (visit[nx][ny][wall + 1]) continue;
				q.push({ nx,ny,cnt + 1,wall + 1 });
				visit[nx][ny][wall + 1] = true;
			}
			else {
				if (visit[nx][ny][wall]) continue;
				q.push({ nx, ny, cnt + 1, wall });
				visit[nx][ny][wall] = true;
			}
		}
	}

	cout << "-1\n";
	return;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}