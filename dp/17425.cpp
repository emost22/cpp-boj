#include <iostream>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N;

void init() {
	for (int i = 1; i < MAX; i++) {
		for (int j = i; j < MAX; j += i) {
			dp[j] += i;
		}
		dp[i] += dp[i - 1];
	}
}

void input() {
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	init();
	while (tc--) {
		input();
	}

	return 0;
}