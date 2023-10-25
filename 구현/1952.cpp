#include <iostream>
#define MAX 101
using namespace std;

bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void func() {
	int x = 0;
	int y = 0;
	int d = 0;
	int ret = 0;
	int cnt = 1;
	visit[x][y] = true;
	while (1) {
		if (cnt == N * M) break;

		int nx = x + direct[d][0];
		int ny = y + direct[d][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) {
			ret++;
			d = (d + 1) % 4;
			continue;
		}

		cnt++;
		visit[nx][ny] = true;
		x = nx;
		y = ny;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}