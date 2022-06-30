#include <iostream>
#include <algorithm>
#define MAX_N 3001
#define MAXNUM 1000001
using namespace std;
typedef long long ll;

int flag[MAXNUM];
ll dp[MAX_N][MAX_N], list[MAX_N];
int N;

void func() {
	ll ans = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			int diff = list[j] - list[i];
			int next = list[j] + diff;

			if (next >= MAXNUM) continue;
			if (!flag[next]) continue;

			dp[i][j] = list[i] + list[j];
			ans = max(ans, dp[i][j]);
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (!dp[i][j]) continue;

			int diff = list[j] - list[i];
			int next = list[j] + diff;

			if (next >= MAXNUM) continue;
			if (!flag[next]) continue;

			dp[j][flag[next]] = dp[i][j] + list[flag[next]];
			ans = max(ans, dp[j][flag[next]]);
		}
	}
	
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		flag[list[i]] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}