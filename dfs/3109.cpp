#include <iostream>
using namespace std;

bool visit[10010][510];
char list[10010][510];
int direct[3][2] = { {-1,1},{0,1},{1,1} };
int N, M, ans;

bool dfs(int x, int y) {
	visit[x][y] = true;
	if (y == M - 1) return true;

	for (int i = 0; i < 3; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visit[nx][ny] || list[nx][ny] == 'x') continue;

		bool chk = dfs(nx, ny);
		if (chk)
			return true;
	}

	return false;
}

void func() {
	for (int i = 0; i < N; i++) {
		if (dfs(i, 0)) ans++;
	}

	cout << ans << '\n';
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

	input();
	func();

	return 0;
}