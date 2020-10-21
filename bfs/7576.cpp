#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int map[1000][1000], visit[1000][1000];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, M, ans;

void bfs(int qsize) {
	for (int T = 0; T < qsize; T++) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
			if (visit[xx][yy]) continue;
			if (!map[xx][yy]) {
				map[xx][yy] = 1;
				visit[xx][yy] = 1;
				q.push(make_pair(xx, yy));
			}
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
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		bfs(q.size());
		ans++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				ans = 0;
				break;
			}
		}
	}

	cout << ans - 1 << '\n';

	return 0;
}