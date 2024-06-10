#include <iostream>
#define MAX 51
using namespace std;
typedef long long ll;

ll lens[MAX];
ll cnts[MAX];
ll X;
int N;

void init() {
	lens[0] = 1;
	cnts[0] = 1;
	for (int i = 1; i <= N; i++) {
		lens[i] = (lens[i - 1] << 1) + 3LL;
		cnts[i] = (cnts[i - 1] << 1) + 1LL;
	}
}

ll solve(int n, ll x) {
	if (!x) return 0LL;
	if (!n) return 1LL;

	if (x <= lens[n - 1] + 1LL) {
		return solve(n - 1, x - 1LL);
	}
	else if (x == lens[n - 1] + 2LL) {
		return cnts[n - 1] + 1LL;
	}
	else {
		return cnts[n - 1] + 1LL + solve(n - 1, x - 2LL - lens[n - 1]);	
	}
}

void func() {
	init();
	cout << solve(N, X) << '\n';
}

void input() {
	cin >> N >> X;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}