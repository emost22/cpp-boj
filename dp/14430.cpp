#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int list[301][301], dp[301][301];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

int func(int x, int y) {
	if (x == N && y == M) return list[x][y];

	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = list[x][y];

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx > N || ny > M) continue;
		ret = max(ret, func(nx, ny) + list[x][y]);
	}

	return ret;
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(1, 1) << '\n';

	return 0;
}