#include <iostream>
#define MAX 10000001
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[MAX];
int N;

void init() {
	dp[1] = 5;
	dp[2] = 20;
	for (int i = 3; i < MAX; i++) {
		dp[i] = (dp[i - 1] * 5) % MOD;
	}
}

void func() {
	cout << dp[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}