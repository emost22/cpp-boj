#include <iostream>
using namespace std;
typedef long long ll;

ll dp[21];
int N;

void init() {
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 20; i++) {
		dp[i] = (i - 1)*(dp[i - 1] + dp[i - 2]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}