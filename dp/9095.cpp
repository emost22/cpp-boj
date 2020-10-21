#include <iostream>
using namespace std;

int dp[11];

void find() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase, N;
	
	find();

	cin >> Testcase;
	while (Testcase--) {
		cin >> N;

		cout << dp[N] << '\n';
	}

	return 0;
}