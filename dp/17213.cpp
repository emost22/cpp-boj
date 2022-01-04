#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 10
#define MAX_M 31
using namespace std;

int dp[MAX_N][MAX_M];
int N, M;

int dfs(int idx, int cnt) {
	if (idx == N) {
		if (!cnt) return 1;
		else return 0;
	}

	int& ret = dp[idx][cnt];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 1; ; i++) {
		if (cnt < i) break;
		ret += dfs(idx + 1, cnt - i);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, M) << '\n';
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