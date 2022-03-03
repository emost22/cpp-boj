#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50001
#define MOD 7
using namespace std;

vector<int> v[MOD];
int dp[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < MOD; i++) {
		if (v[i].empty()) continue;

		int ret = v[i].size() == 1 ? 1 : v[i].back() - v[i].front();
		ans = max(ans, ret);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	v[0].push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] = (dp[i] + dp[i - 1]) % MOD;

		v[dp[i]].push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}