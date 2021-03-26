#include <iostream>
#include <queue>
using namespace std;

typedef struct Point {
	int x;
	int y;
	int target;
	int type;
};

int knightDirect[8][2] = { {2, 1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} };
int bishopDirect[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
int rookDirect[4][2] = { {0,1},{1,0}, {0,-1},{-1,0} };

queue<Point> q;
bool visit[10][10][101][3];
int list[10][10];
int N, ans;

void bfs() {
	for (int t = 1; ; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().x;
			int y = q.front().y;
			int target = q.front().target;
			int type = q.front().type;
			q.pop();

			for (int i = 0; i < 3; i++) {
				if (type == i) continue;
				if (visit[x][y][target][i]) continue;
				q.push({ x, y, target, i });
				visit[x][y][target][i] = true;
			}

			if (type == 0) {
				for (int i = 0; i < 8; i++) {
					int nx = x + knightDirect[i][0];
					int ny = y + knightDirect[i][1];
					int nextTarget = target;
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

					if (list[nx][ny] == target) {
						if (target == N*N) {
							cout << t << '\n';
							return;
						}
						nextTarget++;
						if (visit[nx][ny][nextTarget][type]) continue;
						q.push({ nx,ny,nextTarget, type });
						visit[nx][ny][nextTarget][type] = true;
					}
					else {
						if (visit[nx][ny][nextTarget][type]) continue;
						q.push({ nx,ny,nextTarget, type });
						visit[nx][ny][nextTarget][type] = true;
					}
				}
			}
			else if (type == 1) {
				for (int i = 0; i < 4; i++) {
					int nx = x;
					int ny = y;
					while (1) {
						nx += bishopDirect[i][0];
						ny += bishopDirect[i][1];
						int nextTarget = target;
						if (nx < 0 | ny < 0 || nx >= N || ny >= N) break;

						if (list[nx][ny] == target) {
							if (target == N*N) {
								cout << t << '\n';
								return;
							}
							nextTarget++;
							if (visit[nx][ny][nextTarget][type]) continue;
							q.push({ nx,ny,nextTarget, type });
							visit[nx][ny][nextTarget][type] = true;
						}
						else {
							if (visit[nx][ny][nextTarget][type]) continue;
							q.push({ nx,ny,nextTarget, type });
							visit[nx][ny][nextTarget][type] = true;
						}
					}
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					int nx = x;
					int ny = y;
					while (1) {
						nx += rookDirect[i][0];
						ny += rookDirect[i][1];
						int nextTarget = target;
						if (nx < 0 | ny < 0 || nx >= N || ny >= N) break;

						if (list[nx][ny] == target) {
							if (target == N*N) {
								cout << t << '\n';
								return;
							}
							nextTarget++;
							if (visit[nx][ny][nextTarget][type]) continue;
							q.push({ nx,ny,nextTarget, type });
							visit[nx][ny][nextTarget][type] = true;
						}
						else {
							if (visit[nx][ny][nextTarget][type]) continue;
							q.push({ nx,ny,nextTarget, type });
							visit[nx][ny][nextTarget][type] = true;
						}
					}
				}
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			if (list[i][j] == 1) {
				q.push({ i,j,2,0 }); //knight
				q.push({ i,j,2,1 }); //bishop
				q.push({ i,j,2,2 }); //rook
				visit[i][j][2][0] = true;
				visit[i][j][2][1] = true;
				visit[i][j][2][2] = true;
			}
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