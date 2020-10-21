#include <iostream>
using namespace std;
typedef long long ll;

long long length[81], dp[81];

long long ans(int N) {
	length[1] = 1;
	length[2] = 1;
	dp[1] = 4;
	dp[2] = 6;
	for (int i = 3; i <= N; i++) {
		length[i] = length[i - 1] + length[i - 2];
		dp[i] = (length[i] + length[i - 1]) * 2 + length[i] * 2;
	}

	return dp[N];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << ans(N) << '\n';

	return 0;
}