#include <iostream>
#define MAX 400001
using namespace std;
typedef long long ll;

ll list[MAX];
ll dp[MAX << 1];
int N, M;

void init() {
	for (int i = 1; i <= (N << 1); i++) {
		dp[i] = dp[i - 1] + list[i];
	}
}

void func() {
	init();

	int idx = 1;
	int t, a, b;
	while (M--) {
		cin >> t;
		
		if (t == 1) {
			cin >> a;
			idx -= a;
			if (idx < 1) idx += N;
		}
		else if (t == 2) {
			cin >> a;
			idx = idx + a;
			if (idx > N) idx -= N;
		}
		else {
			cin >> a >> b;
			cout << dp[idx + b - 1] - dp[idx + a - 2] << '\n';
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		list[i + N] = list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}