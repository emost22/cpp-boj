#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<pair<int, int>, int> > q;
char map[50][50];
bool visit[50][50];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, M, ans;

int Max(int x, int y) {
	return x > y ? x : y;
}

void bfs(int x, int y, int cnt) {
	ans = Max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
		if (visit[xx][yy] || map[xx][yy] == 'W') continue;

		q.push(make_pair(make_pair(xx, yy), cnt + 1));
		visit[xx][yy] = true;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				q.push(make_pair(make_pair(i, j), 0));
				visit[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first.first;
					int y = q.front().first.second;
					int cnt = q.front().second;
					q.pop();

					bfs(x, y, cnt);
				}
				memset(visit, false, sizeof(visit));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}