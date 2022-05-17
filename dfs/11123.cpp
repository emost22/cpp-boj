#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visit[nx][ny] || list[nx][ny] == '.') continue;

		dfs(nx, ny);
	}
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || list[i][j] == '.') continue;

			dfs(i, j);
			ans++;
		}
	}

	cout << ans << '\n';
	memset(visit, false, sizeof(visit));
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}