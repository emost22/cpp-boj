#include <iostream>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;

set<pair<int, int> > s[101][101];
ll dp[101][101];
int list[101][101];
int direct[2][2] = { {0,1},{1,0} };
int N, M, K;

ll func(int x, int y) {
	if (x == N && y == M) return 1;

	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx > N || ny > M) continue;
		if (s[x][y].find({ nx,ny }) != s[x][y].end()) continue;

		ret += func(nx, ny);
	}

	return ret;
}

void input() {
	int sx, sy, ex, ey;
	cin >> N >> M >> K;
	while (K--) {
		cin >> sx >> sy >> ex >> ey;
		s[sx][sy].insert({ ex,ey });
		s[ex][ey].insert({ sx,sy });
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0) << '\n';
	
	return 0;
}