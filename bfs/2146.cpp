#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

queue<pair<int, int> > q;
int map[100][100], visit[100][100], s[100];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, cnt = 1, ans, solve = 1000000000;

int Min(int x, int y) {
	return x < y ? x : y;
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	map[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (!map[xx][yy] || visit[xx][yy]) continue;

		dfs(xx, yy);
	}
}

int bfs(int num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == num) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + x_direct[i];
				int yy = y + y_direct[i];

				if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
				if (map[xx][yy] != num && map[xx][yy]) {
					return ans;
				}
				if (map[xx][yy] || visit[xx][yy]) continue;
			
				visit[xx][yy] = 1;
				q.push(make_pair(xx, yy));
			}
		}
		ans++;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 1; i < cnt; i++) {
		memset(visit, 0, sizeof(visit));
		solve = Min(solve, bfs(i));
		ans = 0;
		while (!q.empty()) q.pop();
	}

	cout << solve << '\n';

	return 0;
}