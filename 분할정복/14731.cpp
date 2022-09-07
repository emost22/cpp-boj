#include <iostream>
#define MAX 100000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

pli list[MAX];
int N;

ll mulNum(ll a, ll b) {
	return (a * b) % MOD;
}

ll solve(int n) {
	if (n == -1) return 0LL;
	if (n == 0) return 1LL;
	if (n == 1) return 2LL;

	if (n % 2) {
		ll pre = solve(n - 1);
		return mulNum(pre, 2LL);
	}
	else {
		ll pre = solve(n / 2);
		return mulNum(pre, pre);
	}
}

void func() {
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans = (ans + (list[i].first * solve(list[i].second)) % MOD) % MOD;
	}

	cout << ans << '\n';
}

void input() {
	ll x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		list[i] = { (x * y) % MOD, y - 1 };
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}