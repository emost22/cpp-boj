#include <iostream>
using namespace std;

int list[1001], dp[1001][2], length, lindex;

void dfs(int v) {
	if (dp[v][1] != 0) {
		dfs(dp[v][1]);
	}
	
	cout << list[v] << ' ';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j] && dp[i][0] < dp[j][0] + 1) {
				dp[i][0] = dp[j][0] + 1;
				dp[i][1] = j;
			}
		}
		if (length < dp[i][0]) {
			length = dp[i][0];
			lindex = i;
		}
	}

	cout << length << '\n';
	dfs(lindex);
	cout << '\n';
	
	return 0;
}