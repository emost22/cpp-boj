#include <iostream>
#define MAX 200001
using namespace std;
typedef long long ll;

ll dp[MAX];
ll list[MAX];
int N, Q;

void func() {
	ll ret = 0LL;
	for (int i = 0; i < N; i++) {
		dp[i] = 1LL;
		for (int j = 0; j < 4; j++) {
			dp[i] *= list[(i + j) % N];
		}
		ret += dp[i];
	}

	int q;
	while (Q--) {
		cin >> q;
		q--;
		list[q] = -list[q];

		int idx = q;
		int t = 4;
		while (t--) {
			dp[idx] = -dp[idx];
			ret += (dp[idx] << 1);
			idx = (idx - 1 + N) % N;
		}

		cout << ret << '\n';
	}
}

void input() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
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