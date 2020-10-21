#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, pair<int, int> > > q;
int map[100][100][100], visit[100][100][100];
int x_direct[] = { 0,1,0,-1,0,0 }, y_direct[] = { 1,0,-1,0,0,0 }, z_direct[] = { 0,0,0,0,1,-1 };
int N, M, H, cnt;

void bfs(int x, int y, int z) {
	for (int i = 0; i < 6; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];
		int zz = z + z_direct[i];

		if (xx < 0 || yy < 0 || zz < 0 || xx >= H || yy >= N || zz >= M) continue;
		if (map[xx][yy][zz] || visit[xx][yy][zz]) continue;

		q.push(make_pair(xx, make_pair(yy, zz)));
		map[xx][yy][zz] = 1;
		visit[xx][yy][zz] = 1;
	}
}

bool check() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (!map[i][j][k]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) {
					q.push(make_pair(k, make_pair(i, j)));
					visit[k][i][j] = 1;
				}
			}
		}
	}
	
	while (!q.empty()) {
		int qsize = q.size();
		for (int T = 0; T < qsize; T++) {
			int x = q.front().first;
			int y = q.front().second.first;
			int z = q.front().second.second;
			q.pop();

			bfs(x, y, z);
		}
		cnt++;
	}

	if (check()) {
		cout << cnt - 1 << '\n';
	}
	else cout << "-1\n";

	return 0;
}