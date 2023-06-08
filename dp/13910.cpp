#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#define MAX_N 10001
#define MAX_M 101
using namespace std;

unordered_set<int> s;
int dp[MAX_N];
int arrList[MAX_M];
int N, M;

void func() {
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < M; i++) {
		for (int j = i + 1; j <= M; j++) {
			if (arrList[i] + arrList[j] >= MAX_N) continue;

			s.insert(arrList[i] + arrList[j]);
		}
	}

	for (auto x : s) {
		dp[x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] != -1) continue;
		for (int j = 1; j < i; j++) {
			if (dp[j] == -1 || dp[i - j] == -1) continue;

			if (dp[i] == -1) dp[i] = dp[j] + dp[i - j];
			else dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N] << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> arrList[i];
		s.insert(arrList[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}