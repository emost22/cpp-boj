#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10][1 << 10];
char list[10][10];
int N, M;

int func(int idx, int pre) {
	if (idx == N) return 0;
	
	int &ret = dp[idx][pre];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < (1 << M); i++) {
		bool flag = true;
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			int y = (1 << j);

			if (!(y & i)) continue;

			if (list[idx][j] == 'x') flag = false;
			if (j > 0) {
				if (pre & (y >> 1)) flag = false;
				if (i & (y >> 1)) flag = false;
			}
			if (j < M - 1) {
				if (pre & (y << 1)) flag = false;
				if (i & (y << 1)) flag = false;
			}
			cnt++;
		}
		if (!flag) continue;

		ret = max(ret, func(idx + 1, i) + cnt);
	}

	return ret;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

void init() {
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		init();
		input();
		cout << func(0, 0) << '\n';
	}

	return 0;
}