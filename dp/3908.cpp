#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
bool sosu[1200];
int dp[1121][15];

void init() {
	for (int i = 2; i < 1200; i++) {
		if (sosu[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < 1200; j++) {
			if (sosu[i * j]) continue;
			sosu[i * j] = true;
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < prime.size(); i++) {
		for (int j = 1120; j >= prime[i]; j--) {
			for (int k = 1; k <= 14; k++) {
				dp[j][k] += dp[j - prime[i]][k - 1];
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	init();
	
	int Testcase, N, K;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N >> K;
		cout << dp[N][K] << '\n';
	}

	return 0;
}