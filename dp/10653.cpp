#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int dp[MAX][MAX];
int dis[MAX][MAX];
int N, K;

void init() {
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			dis[i][j] = abs(list[i].first - list[j].first) + abs(list[i].second - list[j].second);
		}
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dis[i - 1][i];
	}
}

void func() {
	init();

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = 1e9;
			for (int k = 0; k <= j; k++) {
				if (i - 1 - k < 1) break;
				dp[i][j] = min(dp[i][j], dp[i - 1 - k][j - k] + dis[i - 1 - k][i]);
			}
		}
	}

	int ret = 1e9;
	for (int i = 0; i <= K; i++) {
		ret = min(ret, dp[N][i]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}