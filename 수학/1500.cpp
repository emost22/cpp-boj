#include <iostream>
using namespace std;
typedef long long ll;

ll S, K;

void func() {
	ll x = S / K;
	int y = S % K;
	
	ll ret = 1;
	for (int i = 0; i < y; i++) {
		ret *= (x + 1);
	}

	for (int i = y; i < K; i++) {
		ret *= x;
	}

	cout << ret << '\n';
}

void input() {
	cin >> S >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}