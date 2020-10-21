#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

queue<pair<int, int> > q;
stack<pair<int, int> > w;
bool visit[8][8];
int map[8][8], N, M, cnt, ans;
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };

int Max(int x, int y) {
	return x > y ? x : y;
}

int bfs() {
	cnt = 0;
	queue<pair<int, int> > qq;
	int map2[8][8] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map2[i][j] = map[i][j];
		}
	}
	qq = q;

	while (!qq.empty()) {
		int qsize = qq.size();
		for (int T = 0; T < qsize; T++) {
			int x = qq.front().first;
			int y = qq.front().second;
			visit[x][y] = true;
			qq.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + x_direct[i];
				int yy = y + y_direct[i];

				if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
				if (visit[xx][yy] || map2[xx][yy] == 1 || map2[xx][yy] == 3) continue;

				map2[xx][yy] = 2;
				qq.push(make_pair(xx, yy));
				visit[xx][yy] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 0) cnt++;
		}
	}
	memset(visit, false, sizeof(visit));
	return cnt;
}

void wall() {
	if (w.size() == 3) {
		ans = Max(ans, bfs());
		map[w.top().first][w.top().second] = 0;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				map[i][j] = 3;
				w.push(make_pair(i, j));
				wall();
				w.pop();
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}

	wall();
	cout << ans << '\n';

	return 0;
}