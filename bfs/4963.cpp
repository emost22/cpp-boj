#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int w, h, ans;
bool visit[50][50];
int map[50][50];
pair<int, int> direct[] = { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextx = x + direct[i].first;
			int nexty = y + direct[i].second;

			if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w) continue;
			if (visit[nextx][nexty] || !map[nextx][nexty]) continue;

			q.push({ nextx, nexty });
			visit[nextx][nexty] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> w >> h;
		if (!w) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && map[i][j]) {
					visit[i][j] = true;
					q.push({ i,j });
					bfs();
					ans++;
				}
			}
		}

		cout << ans << '\n';
		ans = 0;
		memset(visit, false, sizeof(visit));
	}

	return 0;
}