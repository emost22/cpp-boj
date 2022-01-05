#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 20
#define INF 1e9
using namespace std;
typedef pair<int, int> pi;

int dp[MAX][2];
pi list[MAX];
int N, K;

int dfs(int idx, int flag) {
	if (idx == N - 1) return 0;

	int& ret = dp[idx][flag];
	if (ret != -1) return ret;
	ret = INF;

	if (idx + 1 <= N - 1) {
		ret = min(ret, dfs(idx + 1, flag) + list[idx].first);
	}

	if (idx + 2 <= N - 1) {
		ret = min(ret, dfs(idx + 2, flag) + list[idx].second);
	}

	if (idx + 3 <= N - 1 && !flag) {
		ret = min(ret, dfs(idx + 3, !flag) + K);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> list[i].first >> list[i].second;
	}
	cin >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}