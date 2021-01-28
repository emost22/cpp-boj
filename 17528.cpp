#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

int dp[251][62501][2];
int list1[251], list2[251], N;

int func(int idx, int now, int t) {
	if (idx == N + 1) return now;

	if (dp[idx][now][t] != -1) return dp[idx][now][t];
	dp[idx][now][t] = INF;

	if (t) {
		dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, now + list1[idx], t));

		if (now < list2[idx]) {
			dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, list2[idx] - now, 1 - t) + now);
		}
		else {
			dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, now - list2[idx], t) + list2[idx]);
		}
	}
	else {
		dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, now + list2[idx], t));

		if (now < list1[idx]) {
			dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, list1[idx] - now, 1 - t) + now);
		}
		else {
			dp[idx][now][t] = min(dp[idx][now][t], func(idx + 1, now - list1[idx], t) + list1[idx]);
		}
	}

	return dp[idx][now][t];
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list1[i] >> list2[i];
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(1, 0, 0) << '\n';

	return 0;
}