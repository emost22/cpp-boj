#include <iostream>
#define MAX 1001
using namespace std;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

bool dfs(int x, int y) {
	if (x == N - 1) return true;

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (list[nx][ny] == '1' || visit[nx][ny]) continue;

		if (dfs(nx, ny)) return true;
	}

	return false;
}

void func() {
	for (int i = 0; i < M; i++) {
		if (visit[0][i] || list[0][i] == '1') continue;
		if (dfs(0, i)) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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