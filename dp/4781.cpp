#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

pair<int, int> list[5001];
ll dp[10001];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			if (list[i].second > j) continue;

			dp[j] = max(dp[j], dp[j - list[i].second] + list[i].first);
		}
	}

	cout << dp[M] << '\n';
}

void input() {
	double d;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> d;
		list[i].second = d * 100 + 0.5;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	double d;
	while (1) {
		cin >> N >> d;
		M = d * 100 + 0.5;
		if (!N) return 0;

		input();
		func();
		memset(dp, 0, sizeof(dp));
	}
}