#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX][MAX], list[MAX];
int N, M;

int solve(int idx, int len) {
	if (idx == N) return 0;

	int& ret = dp[idx][len];
	if (ret != -1) return ret;
	
	ret = (M - len + 1) * (M - len + 1) + solve(idx + 1, list[idx] + 1);
	if (len + list[idx] <= M) {
		ret = min(ret, solve(idx + 1, len + list[idx] + 1));
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
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