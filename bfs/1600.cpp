#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, pair<int, int> > > q;
bool visit[200][200][31];
int map[200][200];
int x_direct[] = { 0,1,0,-1,-2,-1,1,2,2,1,-1,-2 }, y_direct[] = { 1,0,-1,0,1,2,2,1,-1,-2,-2,-1 };
int K, H, W, ans = -1;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int horse = q.front().second.second;
		q.pop();

		if (x == H - 1 && y == W - 1) {
			ans = cnt;
			return;
		}

		for (int i = 0; i < 12; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= H || yy >= W) continue;
			if (map[xx][yy] == 1) continue;

			if (x_direct[i] == 2 || x_direct[i] == -2 || y_direct[i] == 2 || y_direct[i] == -2) {
				if (visit[xx][yy][horse + 1] || horse == K) continue;
				q.push(make_pair(make_pair(xx, yy), make_pair(cnt + 1, horse + 1)));
				visit[xx][yy][horse + 1] = true;
			}
			else {
				if (visit[xx][yy][horse]) continue;
				q.push(make_pair(make_pair(xx, yy), make_pair(cnt + 1, horse)));
				visit[xx][yy][horse] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	visit[0][0][0] = true;
	bfs();

	cout << ans << '\n';

	return 0;
}