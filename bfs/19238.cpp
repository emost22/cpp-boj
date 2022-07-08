#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 21
using namespace std;
typedef pair<int, int> pii;

typedef struct Point {
	int x;
	int y;
	int dis;
}Point;

vector<pair<pii, pii> > info;
int list[MAX][MAX], guest[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K, X, Y;

bool cmp(Point a, Point b) {
	if (a.dis == b.dis) {
		if (a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	}
	else return a.dis < b.dis;
}

int findNext(int sx, int sy) {
	queue<pii> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	vector<Point> v;
	for (int t = 0; !q.empty(); t++) {
		if (t > K) break;

		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (guest[x][y]) {
				v.push_back({ x,y,t });
				continue;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
				if (visit[nx][ny] || list[nx][ny]) continue;

				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

		if (!v.empty()) break;
	}

	if (v.empty()) return -1;
	
	sort(v.begin(), v.end(), cmp);
	K -= v[0].dis;

	return guest[v[0].x][v[0].y];
}

int bfs() {
	int sx = X;
	int sy = Y;
	int cnt = 0;
	while (1) {
		int idx = findNext(sx, sy);
		if (idx == -1) {
			break;
		}

		pair<pii, pii> next = info[idx - 1];
		
		memset(visit, false, sizeof(visit));
		queue<pii> q;
		q.push({ next.first.first,next.first.second });
		visit[next.first.first][next.first.second] = true;
		bool flag = false;
		for (int t = 0; !q.empty(); t++) {
			if (t > K) break;

			int qsize = q.size();
			while (qsize--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (x == next.second.first && y == next.second.second) {
					K += t;
					sx = x;
					sy = y;
					flag = true;
					break;
				}

				for (int d = 0; d < 4; d++) {
					int nx = x + direct[d][0];
					int ny = y + direct[d][1];

					if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
					if (visit[nx][ny] || list[nx][ny]) continue;

					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}

			if (flag) break;
		}
		if (!flag) break;
		guest[next.first.first][next.first.second] = 0;
		cnt++;
		if (cnt == M) return K;
		memset(visit, false, sizeof(visit));
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}

	int sx, sy, ex, ey;
	cin >> X >> Y;
	for (int i = 1; i <= M; i++) {
		cin >> sx >> sy >> ex >> ey;
		guest[sx][sy] = i;
		info.push_back({ {sx,sy},{ex,ey} });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}