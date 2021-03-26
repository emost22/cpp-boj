#include <iostream>
#include <queue>
using namespace std;

typedef struct Point {
	int sx;
	int sy;
};

int list[1001][1001];
bool visit[1001][1001];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, H, W, sx, sy, desx, desy;

void bfs() {
	queue<Point> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;

	for (int t = 0; ; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().sx;
			int y = q.front().sy;
			q.pop();

			if (x == desx && y == desy) {
				cout << t << '\n';
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];
				int ex = nx + H - 1;
				int ey = ny + W - 1;
				if (nx < 1 || ny < 1 || ex > N || ey > M) continue;
				if (visit[nx][ny]) continue;
				if (list[ex][ey] - list[nx - 1][ey] - list[ex][ny - 1] + list[nx - 1][ny - 1]) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}

		if (q.empty()) break;
	}

	cout << "-1\n";
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
			list[i][j] += (list[i - 1][j] + list[i][j - 1] - list[i - 1][j - 1]);
		}
	}
	cin >> H >> W >> sx >> sy >> desx >> desy;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}