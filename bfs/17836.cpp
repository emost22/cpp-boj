#include <iostream>
#include <queue>
using namespace std;

typedef struct Point {
	int x;
	int y;
	bool chk;
};

queue<Point> q;
bool visit[101][101][2];
int list[101][101];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, T;

void bfs() {
	q.push({ 1,1,false });
	visit[1][1][0] = true;
	for (int t = 1; t <= T; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().x;
			int y = q.front().y;
			bool chk = q.front().chk;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
				if (list[nx][ny] == 2 && !visit[nx][ny][1]) {
					q.push({ nx,ny,true });
					visit[nx][ny][1] = true;
				}
				else if (list[nx][ny] == 0 && !visit[nx][ny][chk]) {
					q.push({ nx,ny,chk });
					visit[nx][ny][chk] = true;
					if (nx == N && ny == M) {
						cout << t << '\n';
						return;
					}
				}
				else if (list[nx][ny] == 1 && chk && !visit[nx][ny][chk]) {
					q.push({ nx,ny,chk });
					visit[nx][ny][chk] = true;
					if (nx == N && ny == M) {
						cout << t << '\n';
						return;
					}
				}
			}
		}
	}

	cout << "Fail\n";
}

void input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}