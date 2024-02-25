#include <iostream>
#define MAX_N 100001
#define MAX_M 6
using namespace std;
typedef pair<int, int> pii;

pii list[MAX_N];
int dp[MAX_N][MAX_M];
int N;
pii ret;

void solve(int value, int idx) {
	if (ret.first < value) {
		ret = { value, idx };
	}
	else if (ret.first == value) {
		if (ret.second > idx) {
			ret = { value, idx };
		}
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i][list[i].first] = dp[i - 1][list[i].first] + 1;
		dp[i][list[i].second] = dp[i - 1][list[i].second] + 1;
		solve(dp[i][list[i].first], list[i].first);
		solve(dp[i][list[i].second], list[i].second);
	}

	cout << ret.first << ' ' << ret.second << '\n';
}

void input() {
	cin >> N;
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