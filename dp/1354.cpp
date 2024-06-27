#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll, ll> m;
ll N, p, q, x, y;

ll solve(ll n) {
	if (n <= 0) return 1LL;
	if (m.find(n) != m.end()) return m[n];
	return m[n] = solve(n / p - x) + solve(n / q - y);
}

void func() {
	cout << solve(N) << '\n';
}

void input() {
	cin >> N >> p >> q >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}