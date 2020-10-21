#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > now, nextq;
int map[1000][1000], visit[1000][1000];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, M, cnt, ans;

void bfs() {
	while (!now.empty()) {
		int x = now.front().first;
		int y = now.front().second;
		now.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
			if (map[xx][yy] == -1 || visit[xx][yy]) continue;

			nextq.push(make_pair(xx, yy));
			map[xx][yy] = 1;
			visit[xx][yy] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (!map[i][j]) cnt++;
			else if (map[i][j] == 1) {
				now.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}

	if (!cnt) cout << "0\n";
	else {
		while (!now.empty()) {
			bfs();

			now = nextq;
			ans++;
			while (!nextq.empty()) nextq.pop();
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!map[i][j]) {
					ans = 0;
					break;
				}
			}
			if (!ans) break;
		}

		cout << ans - 1 << '\n';
	}

	return 0;
}