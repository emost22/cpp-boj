#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

pii dp[MAX][MAX];
int list[MAX][MAX];
bool chk[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

pii solve(int x, int y, int ex, int ey) {
	if (x == ex && y == ey) return { list[x][y],0 };
	
	pii& ret = dp[x][y];
	if (ret.first != -1) return ret;
	ret = { 0, 0 };
	
	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx > ex || ny > ey) continue;

		pii next = solve(nx, ny, ex, ey);
		if (chk[nx][ny]) next.second++;
		if (ret.first < next.first + list[x][y]) {
			ret = { next.first + list[x][y], next.second };
		}
		else if (ret.first == next.first + list[x][y]) {
			ret.second = max(ret.second, next.second);
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	pii ret = solve(1, 1, N, N);
	cout << ret.first << ' ' << ret.second << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}

	int x, y;
	cin >> M;
	while (M--) {
		cin >> x >> y;
		chk[x][y] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}