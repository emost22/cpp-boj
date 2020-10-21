#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;

queue<pair<pair<int, int>, int> > q;
queue<pair<int, int> > f;
bool visit[1001][1001];
char map[1001][1001];
int firemap[1001][1001];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int R, C, ans;

int Min(int x, int y) {
	return x < y ? x : y;
}

void bfsfire() {
	int cnt = 1;
	firemap[f.front().first][f.front().second] = -1;

	while (!f.empty()) {
		int fsize = f.size();
		for (int T = 0; T < fsize; T++) {
			int x = f.front().first;
			int y = f.front().second;
			f.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + x_direct[i];
				int yy = y + y_direct[i];

				if (xx <= 0 || yy <= 0 || xx > R || yy > C) continue;
				if (map[xx][yy] == '#' || firemap[xx][yy] != 0) continue;

				f.push({ xx, yy });
				firemap[xx][yy] = cnt;
			}
		}
		cnt++;
	}
}

void bfs() {
	ans = INF;
	while (!q.empty()) {
		int qsize = q.size();
		for (int T = 0; T < qsize; T++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (x == 1 || y == 1 || x == R || y == C) {
				ans = Min(ans, cnt);
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int xx = x + x_direct[i];
				int yy = y + y_direct[i];

				if (xx <= 0 || yy <= 0 || xx > R || yy > C) continue;
				if (map[xx][yy] == '#' || visit[xx][yy]) continue;
				if (map[xx][yy] == 'F' || (firemap[xx][yy] != 0 && firemap[xx][yy] <= cnt)) continue;

				q.push({ {xx, yy}, cnt + 1 });
				visit[xx][yy] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				q.push({ {i, j}, 1 });
				visit[i][j] = true;
			}
			if (map[i][j] == 'F') {
				f.push({ i, j });
			}
		}
	}

	if (!f.empty()) bfsfire();
	bfs();

	if (ans == INF) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';

	return 0;
}