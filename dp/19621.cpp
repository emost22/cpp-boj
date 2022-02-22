#include <iostream>
#include <algorithm>
#define MAX 26
using namespace std;
typedef pair<pair<int, int>, int> ppi;

ppi list[MAX];
int dp[MAX][2];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][0] + list[i].second, dp[i - 1][1]);
	}

	cout << max(dp[N][0], dp[N][1]) << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first.first >> list[i].first.second >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}