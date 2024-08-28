#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll x = 1LL;
	int cnt = 0;
	ll tmp = N;
	while (tmp) {
		cnt += !(tmp & 1);
		x <<= 1;
		tmp >>= 1;
	}
	x--;

	if (!cnt) {
		cout << "1\n";
		cout << N << '\n';
	}
	else {
		cout << "2\n";
		cout << x - N << '\n' << N << '\n';
	}
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