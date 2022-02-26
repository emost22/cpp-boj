#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N;

bool dfs(int x, int y) {
	if (x == N - 1 && y == N - 1) return true;
	visit[x][y] = true;

	int d = list[x][y];
	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0] * d;
		int ny = y + direct[i][1] * d;

		if (nx >= N || ny >= N) continue;
		if (visit[nx][ny]) continue;

		if (dfs(nx, ny)) return true;
	}

	return false;
}

void func() {
	if (dfs(0, 0)) cout << "HaruHaru\n";
	else cout << "Hing\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
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