#include <iostream>
using namespace std;
typedef long long ll;

ll N, A, B, C;

ll fact(ll n) {
	ll ret = 1;
	for (int i = 2; i <= n; i++) {
		ret *= i;
	}

	return ret;
}

void func() {
	cout << fact(N) / fact(A) / fact(B) / fact(C) << '\n';
}

void input() {
	cin >> N >> A >> B >> C;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}