#include <iostream>
#include <cstring>
#define MAX_M 501
#define MAX_N 10010
using namespace std;

int dp[MAX_N][MAX_M];
bool chk[MAX_N];
int N, M;

int solve(int idx, int k) {
	if (idx == N) return 0;

	int& ret = dp[idx][k];
	if (ret != -1) return ret;
	ret = 1e9;

	for (int i = k - 1; i <= k + 1; i++) {
		if (i <= 0 || idx + i > N) continue;
		if (chk[idx + i]) continue;
		ret = min(ret, solve(idx + i, i) + 1);
	}

	return ret;
}

void func() {
	if (chk[2]) {
		cout << "-1\n";
		return;
	}

	memset(dp, -1, sizeof(dp));
	int ret = solve(2, 1) + 1;
	if (ret == 1e9 + 1) ret = -1;
	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		chk[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}