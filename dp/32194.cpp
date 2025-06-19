#include <iostream>
#define MAX 200001
using namespace std;

int dp[MAX];
int N;

void func() {
	dp[1] = 1;

	const char* ret[] = { "No", "Yes"};
	int t, x, y;
	for (int i = 2; i <= N + 1; i++) {
		cin >> t >> x >> y;

		int idx = 0;
		if (t == 1) {
			idx = (dp[y] - dp[x - 1] == y - x + 1);
			dp[i] = dp[i - 1] + idx;
		}
		else {
			idx = (dp[y] - dp[x - 1] == 0);
			dp[i] = dp[i - 1] + idx;
		}

		cout << ret[idx] << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}