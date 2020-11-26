#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q, waterq;
char list[1510][1510];
int N, M, sx, sy, ex, ey;
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool visit[1510][1510];

bool bfs() {
	queue<pair<int, int> > nq;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny]) continue;
			if (list[nx][ny] == 'X') {
				visit[nx][ny] = true;
				nq.push({ nx,ny });
			}
			else if (list[nx][ny] == 'L') {
				return true;
			}
			else {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	q = nq;
	return false;
}

void oneday() {
	queue<pair<int, int> > nwaterq;
	while (!waterq.empty()) {
		int x = waterq.front().first;
		int y = waterq.front().second;
		waterq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] == 'X') {
				list[nx][ny] = '.';
				nwaterq.push({ nx,ny });
			}
		}
	}

	waterq = nwaterq;
}

void input() {
	sx = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < M; j++) {
			if (list[i][j] != 'X') {
				waterq.push({ i,j });
			}
			if (list[i][j] == 'L') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	q.push({ sx,sy });
	visit[sx][sy] = true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int T = 0; ; T++) {
		if (bfs()) {
			cout << T << '\n';
			return 0;
		}
		oneday();
	}
}