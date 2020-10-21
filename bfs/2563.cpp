#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
bool visit[101][101];
int map[101][101], x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 }, N, ans;

void bfs(int size) {
	ans++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx <= 0 || yy <= 0 || xx > 100 || yy > 100) continue;
			if (visit[xx][yy] || size != map[xx][yy]) continue;

			q.push({ xx,yy });
			visit[xx][yy] = true;
			ans++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				map[i][j]++;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] && !visit[i][j]) {
				q.push({ i, j });
				visit[i][j] = true;
				bfs(map[i][j]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}