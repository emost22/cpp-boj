#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 1000000000
using namespace std;

string str;
int dp[1001];
int N;

int func(int idx, char ch) {
	if (idx == N) {
		return 0;
	}
	if (dp[idx] != -1) return dp[idx];
	dp[idx] = INF;

	if (ch == 'B') {
		for (int i = idx; i < N; i++) {
			if (str[i] != 'O') continue;
			dp[idx] = min(dp[idx], func(i + 1, 'O') + (i - idx + 1)*(i - idx + 1));
		}
	}
	else if (ch == 'O') {
		for (int i = idx; i < N; i++) {
			if (str[i] != 'J') continue;
			dp[idx] = min(dp[idx], func(i + 1, 'J') + (i - idx + 1)*(i - idx + 1));
		}
	}
	else {
		for (int i = idx; i < N; i++) {
			if (str[i] != 'B') continue;
			dp[idx] = min(dp[idx], func(i + 1, 'B') + (i - idx + 1)*(i - idx + 1));
		}
	}

	return dp[idx];
}

void input() {
	cin >> N >> str;
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	int result = func(1, 'B');
	if (result == INF) cout << "-1\n";
	else cout << result << '\n';

	return 0;
}