#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
int dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N, M;

int solve(int x, int y, int sx, int sy, int ex, int ey) {
	if (x == ex && y == ey) return 0;

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx < sx || ny < sy || nx > ex || ny > ey) continue;
		
		ret = max(ret, solve(nx, ny, sx, sy, ex, ey) + list[nx][ny]);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	sort(v.begin(), v.end());
	int x = 1;
	int y = 1;
	int ret = list[x][y];
	for (auto xy : v) {
		int ex = xy.first;
		int ey = xy.second;

		if (x > ex || y > ey) {
			cout << "-1\n";
			return;
		}

		ret += solve(x, y, x, y, ex, ey);
		x = ex;
		y = ey;
	}

	cout << ret << '\n';
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
		v.push_back({ x,y });
	}
	v.push_back({ N,N });
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}