#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[2][500001];
int list[50];
int N, sum;

void func() {
	dp[0][0] = 0;
	dp[0][list[0]] = list[0];
	int t = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (dp[1 - t][j] == -1) continue;

			dp[t][j] = max(dp[t][j], dp[1 - t][j]);
			dp[t][j + list[i]] = max(dp[t][j + list[i]], dp[1 - t][j] + list[i]);
			if (j < list[i]) {
				dp[t][list[i] - j] = max(dp[t][list[i] - j], dp[1 - t][j] + (list[i] - j));
			}
			else {
				dp[t][j - list[i]] = max(dp[t][j - list[i]], dp[1 - t][j]);
			}
		}
		t = 1 - t;
	}

	if (!dp[1 - t][0]) dp[1 - t][0] = -1;
	cout << dp[1 - t][0] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}