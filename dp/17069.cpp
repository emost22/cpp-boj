#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll list[32][32], dp[32][32][32][32];
int N;

ll func(int fx, int fy, int sx, int sy) {
	if (sx == N - 1 && sy == N - 1) return 1;
	
	ll &ret = dp[fx][fy][sx][sy];
	if (ret != -1) return ret;
	ret = 0;

	if (fx != sx && fy != sy) { // 대각
		if (sy + 1 < N && !list[sx][sy + 1]) ret += func(sx, sy, sx, sy + 1);
		if (sx + 1 < N && !list[sx + 1][sy]) ret += func(sx, sy, sx + 1, sy);
	}
	else if (fx == sx) { // 세로
		if (sy + 1 < N && !list[sx][sy + 1]) ret += func(sx, sy, sx, sy + 1);
	}
	else { // 가로
		if (sx + 1 < N && !list[sx + 1][sy]) ret += func(sx, sy, sx + 1, sy);
	}

	if (sx + 1 < N && sy + 1 < N && !list[sx + 1][sy] && !list[sx][sy + 1] && !list[sx + 1][sy + 1]) ret += func(sx, sy, sx + 1, sy + 1);

	return ret;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0, 0, 1) << '\n';

	return 0;
}