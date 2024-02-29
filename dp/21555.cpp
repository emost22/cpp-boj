#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef long long ll;

ll dp[MAX][2];
ll list[MAX][2];
ll K;
int N;

void func() {
	dp[1][0] = list[1][0];
	dp[1][1] = list[1][1];
	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][0] + list[i][0], dp[i - 1][1] + list[i][0] + K);
		dp[i][1] = min(dp[i - 1][1] + list[i][1], dp[i - 1][0] + list[i][1] + K);
	}

	cout << min(dp[N][0], dp[N][1]) << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i][0];
	}

	for (int i = 1; i <= N; i++) {
		cin >> list[i][1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}