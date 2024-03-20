#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int dp[MAX];
int N, K;

int getFreeze(double x) {
	if (x >= 1.98) return 2;
	else if (x >= 0.99) return 1;
	else return 0;
}

void func() {
	int maxValue = 0;
	for (int i = 1; i <= N; i++) {
		maxValue = max(maxValue, list[i]);
	}

	int l = 1;
	int r = 1;
	int ret = 0;
	while (r <= N) {
		if (dp[r] - dp[l - 1] <= K) {
			ret = max(ret, r - l + 1);
			r++;
		}
		else {
			l++;
		}
	}

	cout << ret << '\n' << maxValue << '\n';
}

void input() {
	double x;
	cin >> x >> N;
	K = getFreeze(x);
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i] = dp[i - 1] + (list[i] == 0);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}