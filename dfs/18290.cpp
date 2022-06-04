#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K, ans;

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == K) {
		ans = max(ans, sum);
		return;
	}
	if (x == N) return;

	int j = y;
	for (int i = x; i < N; i++) {
		for (; j < M; j++) {
			bool flag = true;
			for (int d = 0; d < 4; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny]) {
					flag = false;
					break;
				}
			}

			if (!flag) continue;
			int nx = i;
			int ny = j;
			if (ny == M - 1) {
				nx = i + 1;
				ny = 0;
			}
			else ny++;

			visit[i][j] = true;
			dfs(nx, ny, cnt + 1, sum + list[i][j]);
			visit[i][j] = false;
		}
		j = 0;
	}
}

void func() {
	ans = -1e9;
	dfs(0, 0, 0, 0);
	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}