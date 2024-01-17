#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N, M;

void func() {
	int x, y;
	while (M--) {
		cin >> x >> y;
		cout << dp[y + 1] - dp[x] << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}