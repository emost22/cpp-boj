#include <iostream>
#define MAX 1001
using namespace std;

char list[MAX][MAX];
int visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, ans;

void dfs(int x, int y) {
	visit[x][y] = 1;

	int d = 0;
	if (list[x][y] == 'R') d = 0;
	else if (list[x][y] == 'D') d = 1;
	else if (list[x][y] == 'L') d = 2;
	else d = 3;

	int nx = x + direct[d][0];
	int ny = y + direct[d][1];

	if (visit[nx][ny] == 1) ans++;
	if (!visit[nx][ny]) dfs(nx, ny);
	visit[x][y] = 2;
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;

			dfs(i, j);
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