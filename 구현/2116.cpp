#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int list[10000][6], rlist[6];
int N, ans;

void init() {
	rlist[0] = 5;
	rlist[5] = 0;

	rlist[1] = 3;
	rlist[3] = 1;

	rlist[2] = 4;
	rlist[4] = 2;
}

void dfs(int idx, int value, int sum) {
	if (idx == N) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (list[idx][i] == value) {
			int rx = rlist[i];

			int max_value = 0;
			for (int j = 0; j < 6; j++) {
				if (j == i || j == rx) continue;

				max_value = max(max_value, list[idx][j]);
			}

			dfs(idx + 1, list[idx][rx], sum + max_value);
			break;
		}
	}
}

void func() {
	for (int i = 0; i < 6; i++) {
		int rx = rlist[i];

		int max_value = 0;
		for (int j = 0; j < 6; j++) {
			if (j == i || j == rx) continue;

			max_value = max(max_value, list[0][j]);
		}

		dfs(1, list[0][rx], max_value);
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) cin >> list[i][j];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();
	cout << ans << '\n';

	return 0;
}