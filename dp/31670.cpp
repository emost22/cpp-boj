#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;

ll dp[MAX][2];
ll list[MAX];
int N;

void func() {
	dp[1][1] = list[1];
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + list[i];
	}

	cout << min(dp[N][0], dp[N][1]) << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}