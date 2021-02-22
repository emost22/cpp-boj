#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct point {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
}point;

queue<point> q;
bool visit[11][11][11][11];
char list[11][11];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;

			bool redchk = false;
			bool bluechk = false;
			while (1) {
				nrx += direct[i][0];
				nry += direct[i][1];

				if (list[nrx][nry] == '#') {
					nrx -= direct[i][0];
					nry -= direct[i][1];
					break;
				}
				else if (list[nrx][nry] == 'O') {
					redchk = true;
					break;
				}
			}

			int nbx = bx;
			int nby = by;

			while (1) {
				nbx += direct[i][0];
				nby += direct[i][1];

				if (list[nbx][nby] == '#') {
					nbx -= direct[i][0];
					nby -= direct[i][1];
					break;
				}
				else if (list[nbx][nby] == 'O') {
					bluechk = true;
					break;
				}
			}

			if (bluechk) continue;
			else if (redchk) {
				cout << cnt + 1 << '\n';
				return;
			}

			if (nrx == nbx && nry == nby) {
				int reddis = abs(nrx - rx) + abs(nry - ry);
				int bluedis = abs(nbx - bx) + abs(nby - by);

				if (reddis > bluedis) {
					nrx -= direct[i][0];
					nry -= direct[i][1];
				}
				else {
					nbx -= direct[i][0];
					nby -= direct[i][1];
				}
			}

			if (visit[nrx][nry][nbx][nby]) continue;

			q.push({ nrx,nry,nbx,nby,cnt + 1 });
			visit[nrx][nry][nbx][nby] = true;
		}
	}

	cout << "-1\n";
}

void input() {
	int rx, ry, bx, by;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (list[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}

	q.push({ rx,ry,bx,by,0 });
	visit[rx][ry][bx][by] = true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}