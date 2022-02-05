#include <iostream>
#include <string>
#include <algorithm>
#define MAX 41
using namespace std;

string a, b;
int dp[MAX][MAX];
int N, M;

void func() {
	string ans = "";
	int x = N;
	int y = M;
	while (1) {
		if (!x || !y) break;
		if (dp[x][y] != dp[x - 1][y] && dp[x][y] != dp[x][y - 1]) {
			ans += a[x - 1];
			x--;
			y--;
		}
		else if (dp[x][y] != dp[x - 1][y]) {
			y--;
		}
		else x--;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

void init() {
	N = a.size();
	M = b.size();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

void input() {
	cin >> a >> b;
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}