#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[21][21][21], list[21];
int N, lo, ro, M;

int func(int idx, int l, int r) {
	if (idx == M) return 0;

	int &ret = dp[idx][l][r];
	if (ret != -1) return ret;

	ret = min(func(idx + 1, list[idx], r) + abs(l - list[idx]), func(idx + 1, l, list[idx]) + abs(list[idx] - r));

	return ret;
}

void input() {
	cin >> N >> lo >> ro >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}

	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, lo, ro) << '\n';

	return 0;
}