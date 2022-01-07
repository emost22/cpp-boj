#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 11
#define MAX_M 2001
using namespace std;
typedef long long ll;

ll dp[MAX_N][MAX_M];
int N, M;

ll dfs(int idx, int pre) {
	if (idx == 0) return 1;
	if (!pre) return 0;

	ll &ret = dp[idx][pre];
	if (ret != -1) return ret;
	ret = 0;

	ret += dfs(idx - 1, pre / 2);
	ret += dfs(idx, pre - 1);

	return ret;
}

void func() {
	cout << dfs(N, M) << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	memset(dp, -1, sizeof(dp));
	while (tc--) {
		input();
		func();
	}

	return 0;
}