#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[21][100];
int list[100], N;

ll func(int value, int idx) {
	if (idx == N - 1) {
		if (value == list[N - 1]) return dp[value][idx] = 1;
		return dp[value][idx] = 0;
	}

	if (dp[value][idx] != -1) return dp[value][idx];
	else dp[value][idx] = 0;

	if (value + list[idx] <= 20) dp[value][idx] += func(value + list[idx], idx + 1);
	if (value - list[idx] >= 0) dp[value][idx] += func(value - list[idx], idx + 1);

	return dp[value][idx];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << func(list[0], 1) << '\n';

	return 0;
}