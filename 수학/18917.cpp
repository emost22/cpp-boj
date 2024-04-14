#include <iostream>
using namespace std;
typedef long long ll;

int M;

void func() {
	int type;
	ll x;
	ll sum = 0;
	ll ret = 0;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			sum += x;
			ret ^= x;
		}
		else if (type == 2) {
			cin >> x;
			sum -= x;
			ret ^= x;
		}
		else if (type == 3) {
			cout << sum << '\n';
		}
		else {
			cout << ret << '\n';
		}
	}
}

void input() {
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}