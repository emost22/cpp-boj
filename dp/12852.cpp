#include <iostream>
using namespace std;

int dp[1000001], parent[1000001];

void func(int N) {
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		parent[i] = i - 1;

		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3]) {
				parent[i] = i / 3;
				dp[i] = dp[i / 3] + 1;
			}
		}
		
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2]) {
				parent[i] = i / 2;
				dp[i] = dp[i / 2] + 1;
			}
		}
	}
}

void print(int v) {
	cout << dp[v] << '\n';
	for (int i = v; i != 0; i = parent[i]) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	func(N);
	print(N);

	return 0;
}