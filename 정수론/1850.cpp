#include <iostream>
using namespace std;
typedef long long ll;

ll x, y;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int ans = gcd(x, y);
	for (int i = 0; i < ans; i++) {
		cout << 1;
	}
	cout << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}