#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 5
#define MIN_ANS 12
using namespace std;

int list[MAX][MAX][MAX], map[MAX][MAX][MAX];
int order[MAX], ans;
int direct[6][3] = { {0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0} };
bool visit[MAX][MAX][MAX];

int bfs() {
	queue<pair<int, pair<int, int> > > q;
	q.push({ 0,{0,0} });
	memset(visit, false, sizeof(visit));
	visit[0][0][0] = true;
	for (int t = 0; !q.empty(); t++) {
		if (ans <= t) return t;

		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second.first;
			int z = q.front().second.second;
			q.pop();

			if (x == MAX - 1 && y == MAX - 1 && z == MAX - 1) {
				return t;
			}

			for (int d = 0; d < 6; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];
				int nz = z + direct[d][2];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= MAX || ny >= MAX || nz >= MAX) continue;
				if (visit[nx][ny][nz] || !map[nx][ny][nz]) continue;

				q.push({ nx,{ny,nz} });
				visit[nx][ny][nz] = true;
			}
		}
	}

	return -1;
}

bool rotate(int idx) {
	int tmp[MAX][MAX][MAX] = { 0, };
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tmp[idx][i][j] = map[idx][j][MAX - 1 - i];
		}
	}

	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[idx][i][j] == tmp[idx][i][j]) cnt++;
			map[idx][i][j] = tmp[idx][i][j];
		}
	}

	if (cnt == MAX * MAX) return false;
	else return true;
}

void dfs(int idx) {
	if (idx == MAX) {
		if (!map[MAX - 1][MAX - 1][MAX - 1]) {
			return;
		}

		int ret = bfs();
		if (ret != -1) {
			ans = min(ans, ret);
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (map[0][0][0]) {
			dfs(idx + 1);
			if (ans == MIN_ANS) return;
		}

		if (!rotate(idx)) return;
	}
}

void copyArray() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				map[order[i]][j][k] = list[i][j][k];
			}
		}
	}
}

void func() {
	ans = 1e9;
	do {
		copyArray();
		dfs(0);
	} while (next_permutation(order, order + MAX));

	if (ans == 1e9) ans = -1;
	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				cin >> list[i][j][k];
			}
		}
		order[i] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}