#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int visit[300][300];
int x_direct[] = { 2,2,1,1,-1,-1,-2,-2 }, y_direct[] = { 1,-1,2,-2,-2,2,-1,1 };
int N, sx, sy, ex, ey, cnt;
bool ans;

bool bfs(int x, int y) {
	if (x == ex && y == ey) return true;

	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (visit[xx][yy]) continue;

		q.push(make_pair(xx, yy));
		visit[xx][yy] = 1;
	}

	if (x != ex || y != ey) return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N >> sx >> sy >> ex >> ey;

		q.push(make_pair(sx, sy));
		while (!q.empty()) {
			int qsize = q.size();
			for (int T = 0; T < qsize; T++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				ans = bfs(x, y);
				if (ans) {
					break;
				}
			}
			if (ans) break;
			cnt++;
		}

		cout << cnt << '\n';
		ans = false;
		cnt = 0;
		while (!q.empty()) q.pop();
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}