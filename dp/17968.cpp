#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX];
bool chk[MAX][MAX];
int N;

void init() {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int k = 1; 2 * k <= i; k++) {
			chk[i][2 * dp[i - k] - dp[i - 2 * k]] = true;
		}

		for (int j = 1; j < MAX; j++) {
			if (!chk[i][j]) {
				dp[i] = j;
				break;
			}
		}
	}
}

void input() {
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}