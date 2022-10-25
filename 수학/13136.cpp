#include <iostream>
using namespace std;
typedef long long ll;

ll R, C, N;

void func() {
	ll x = R / N + (R % N != 0);
	ll y = C / N + (C % N != 0);

	cout << x * y << '\n';
}

void input() {
	cin >> R >> C >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}