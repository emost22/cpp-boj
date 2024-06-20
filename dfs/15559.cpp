#include <iostream>
#define MAX 1001
using namespace std;

char list[MAX][MAX];
int visit[MAX][MAX];
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M;

int getIdx(char x) {
	if (x == 'N') return 0;
	if (x == 'S') return 1;
	if (x == 'W') return 2;
	return 3;
}

bool solve(int x, int y, int num) {
	visit[x][y] = num;
	int d = getIdx(list[x][y]);
	int nx = x + direct[d][0];
	int ny = y + direct[d][1];
	if (visit[nx][ny]) {
		if (visit[nx][ny] == num) return true;
		return false;
	}

	return solve(nx, ny, num);
}

void func() {
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;
			ret += solve(i, j, ++cnt);
		}
	}
	cout << ret << '\n';
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