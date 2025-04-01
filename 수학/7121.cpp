#include <iostream>
using namespace std;
typedef long long ll;

ll N, M, K;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}

void func() {
	ll x = K / (N + 1);
	ll y = K / (M + 1);
	ll z = K / lcm(N + 1, M + 1);
	cout << K - x - y + z << ' ' << z << ' ' << y - z << ' ' << x - z << '\n';
}

void input() {
	cin >> N >> M >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}