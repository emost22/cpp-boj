#include <iostream>
#define MAX 5
using namespace std;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K, ans;

void dfs(int x, int y, int cnt) {
	if (!x && y == M - 1) {
		if (cnt == K) ans++;
		return;
	}
	if (cnt >= K) return;
	visit[x][y] = true;

	for (int d = 0; d < 4; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (list[nx][ny] == 'T' || visit[nx][ny]) continue;

		dfs(nx, ny, cnt + 1);
		visit[nx][ny] = false;
	}
}

void func() {
	dfs(N - 1, 0, 1);
	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}