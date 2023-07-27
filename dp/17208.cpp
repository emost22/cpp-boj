#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;
typedef pair<int, int> pii;

int dp[MAX][MAX];
pii list[MAX];
int N, M, K;

void func() {
	int ret = 0;
	for (int x = 0; x < N; x++) {
		for (int i = M; i >= 0; i--) {
			for (int j = K; j >= 0; j--) {
				if (list[x].first > i || list[x].second > j) continue;
				dp[i][j] = max(dp[i][j], dp[i - list[x].first][j - list[x].second] + 1);
				ret = max(ret, dp[i][j]);
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
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