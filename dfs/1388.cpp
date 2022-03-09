#include <iostream>
#define MAX 50
using namespace std;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

void dfs(int x, int y, int d) {
	visit[x][y] = true;

	int nx = x + direct[d][0];
	int ny = y + direct[d][1];

	if (nx >= N || ny >= M) return;
	if ((d && list[nx][ny] == '-') || (!d && list[nx][ny] == '|')) return;

	dfs(nx, ny, d);
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;

			dfs(i, j, list[i][j] == '-' ? 0 : 1);
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
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