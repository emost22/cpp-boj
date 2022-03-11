#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 21
using namespace std;

typedef struct Point {
	int fx, fy;
	int sx, sy;
}Point;

queue<Point> q;
char list[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

int bfs() {
	for (int t = 1; t <= 10; t++) {
		int qsize = q.size();
		while (qsize--) {
			Point p = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nfx = p.fx + direct[i][0];
				int nfy = p.fy + direct[i][1];
				int nsx = p.sx + direct[i][0];
				int nsy = p.sy + direct[i][1];

				bool f1 = (nfx < 0 || nfy < 0 || nfx >= N || nfy >= M);
				bool f2 = (nsx < 0 || nsy < 0 || nsx >= N || nsy >= M);
				if (f1 && f2) continue;
				else if (f1 || f2) return t;

				if (list[nfx][nfy] == '#') {
					nfx = p.fx;
					nfy = p.fy;
				}
				if (list[nsx][nsy] == '#') {
					nsx = p.sx;
					nsy = p.sy;
				}
				if (visit[nfx][nfy][nsx][nsy]) continue;

				q.push({ nfx,nfy,nsx,nsy });
				visit[nfx][nfy][nsx][nsy] = true;
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	Point p;
	bool flag = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'o') {
				if (!flag) {
					p.fx = i;
					p.fy = j;
					flag = true;
				}
				else {
					p.sx = i;
					p.sy = j;
				}
			}
		}
	}
	q.push(p);
	visit[p.fx][p.fy][p.sx][p.sy] = true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}