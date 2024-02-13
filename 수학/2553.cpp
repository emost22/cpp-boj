#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ret = 1;
	for (ll i = 1L; i <= N; i++) {
		ret *= i;
		ret %= 100000000;
		while (!(ret % 5)) ret /= 10;
	}

	cout << ret % 10 << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}