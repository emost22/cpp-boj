#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<pair<int, int>, pair<int, int> > > q;
int visit[101][101][4];
int map[101][101], M, N, sx, sy, sd, ex, ey, ed, ans = 1000000000;
int x_direct[] = { -1,0,1,0 }, y_direct[] = { 0,1,0,-1 };

int Min(int x, int y) {
	return x < y ? x : y;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == ex && y == ey && d == ed) {
			ans = Min(ans, cnt);
		}

		int xx = x, yy = y;
		for (int i = 0; i < 3; i++) {
			xx = xx + x_direct[d];
			yy = yy + y_direct[d];

			if (xx <= 0 || yy <= 0 || xx > M || yy > N) break;
			if ((visit[xx][yy][d] != -1 && visit[xx][yy][d] < cnt + 1) || map[xx][yy]) break;

			q.push(make_pair(make_pair(xx, yy), make_pair(d, cnt + 1)));
			visit[xx][yy][d] = cnt + 1;
		}

		if (visit[x][y][(d + 3) % 4] == -1 || visit[x][y][(d + 1) % 4] >= cnt + 1) {
			q.push(make_pair(make_pair(x, y), make_pair((d + 1) % 4, cnt + 1)));
			visit[x][y][(d + 1) % 4] = cnt + 1;
		}
		if (visit[x][y][(d + 3) % 4] == -1 || visit[x][y][(d + 3) % 4] >= cnt + 1) {
			q.push(make_pair(make_pair(x, y), make_pair((d + 3) % 4, cnt + 1)));
			visit[x][y][(d + 3) % 4] = cnt + 1;
		}
	}

	return;
}

int direction(int d) {
	if (d == 1) {
		return d;
	}
	else if (d == 2) {
		return 3;
	}
	else if (d == 3) {
		return 2;
	}
	else {
		return 0;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	memset(visit, -1, sizeof(visit));

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy >> sd >> ex >> ey >> ed;
	sd = direction(sd);
	ed = direction(ed);

	q.push(make_pair(make_pair(sx, sy), make_pair(sd, 0)));
	visit[sx][sy][sd] = 0;
	bfs();

	cout << ans << '\n';

	return 0;
}