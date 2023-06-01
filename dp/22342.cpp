#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2001
using namespace std;

int dp[MAX][MAX], list[MAX][MAX], ans[MAX][MAX];
int N, M;

void func() {
	int ret = 0;
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			dp[i][j] = max(ans[i - 1][j - 1], max(ans[i][j - 1], ans[i + 1][j - 1]));
			ans[i][j] = dp[i][j] + list[i][j];
			ret = max(ret, dp[i][j]);
		}
	}

	cout << ret << '\n';
}

void input() {
	string str;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			list[i][j] = str[j - 1] - '0';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}