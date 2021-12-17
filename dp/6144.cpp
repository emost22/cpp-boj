#include <iostream>
#include <algorithm>
#define MAX_N 3403
#define MAX_M 12881
using namespace std;
typedef pair<int, int> pi;

pi list[MAX_N];
int dp[2][MAX_M];
int N, M;

void func() {
	int t = 1;
	for (int i = 0; i < N; i++) {
		int w = list[i].first;
		int d = list[i].second;
		for (int j = 1; j <= M; j++) {
			if (j < w) dp[t][j] = dp[1 - t][j];
			else dp[t][j] = max(dp[1 - t][j], dp[1 - t][j - w] + d);
		}
		t = 1 - t;
	}

	cout << dp[1 - t][M] << '\n';
}

void input() {
	cin >> N >> M;
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