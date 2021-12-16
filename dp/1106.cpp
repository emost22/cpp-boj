#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;
typedef pair<int, int> pi;

int dp[MAX];
pi list[MAX];
int N, M;

void func() {
	fill(dp + 1, dp + MAX, 1e9);

	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MAX; j++) {
			if (dp[j] == 1e9) continue;

			for (int k = 1; j + k * list[i].second < MAX; k++) {
				dp[j + k * list[i].second] = min(dp[j + k * list[i].second], dp[j] + k * list[i].first);
			}
		}
	}

	for (int i = M; i < MAX; i++) {
		ans = min(ans, dp[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
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