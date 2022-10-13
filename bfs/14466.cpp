#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;
typedef pair<int, int> pii;

vector<pii> list[MAX][MAX], v;
bool visit[MAX][MAX];
int map[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K;

int bfs(int sx, int sy) {
	queue<pii> q;
	visit[sx][sy] = true;
	q.push({ sx,sy });
	int num = map[sx][sy];
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] && map[x][y] != num) {
			ret++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (visit[nx][ny]) continue;

			bool flag = true;
			for (auto a : list[x][y]) {
				if (a.first == nx && a.second == ny) {
					flag = false;
					break;
				}
			}
			if (!flag) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	return M - (ret + 1);
}

void func() {
	int ans = 0;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		ans += bfs(v[i].first, v[i].second);
		memset(visit, 0, sizeof(visit));
	}

	cout << ans / 2 << '\n';
}

void input() {
	int sx, sy, ex, ey;
	cin >> N >> M >> K;
	while (K--) {
		cin >> sx >> sy >> ex >> ey;
		list[sx][sy].push_back({ ex,ey });
		list[ex][ey].push_back({ sx,sy });
	}

	for (int i = 1; i <= M; i++) {
		cin >> sx >> sy;
		map[sx][sy] = i;
		v.push_back({ sx,sy });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}