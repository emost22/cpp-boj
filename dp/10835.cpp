#include <iostream>
#include <cstring>
using namespace std;

int lcard[2001], rcard[2001], dp[2001][2001];

int Max(int x, int y) {
	return x > y ? x : y;
}

int find(int N, int lindex, int rindex) {
	if (lindex > N || rindex > N) return 0;

	if (dp[lindex][rindex] != -1) return dp[lindex][rindex];
	dp[lindex][rindex] = 0;
	if (lcard[lindex] > rcard[rindex]) {
		dp[lindex][rindex] += Max(find(N, lindex + 1, rindex), Max(find(N, lindex + 1, rindex + 1), rcard[rindex] + find(N, lindex, rindex + 1)));
	}
	else {
		dp[lindex][rindex] += Max(find(N, lindex + 1, rindex), find(N, lindex + 1, rindex + 1));
	}

	return dp[lindex][rindex];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> lcard[i];
	for (int i = 1; i <= N; i++) cin >> rcard[i];

	memset(dp, -1, sizeof(dp));

	cout << find(N, 1, 1) << '\n';

	return 0;
}