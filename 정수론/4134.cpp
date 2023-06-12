#include <iostream>
using namespace std;
typedef long long ll;

ll x;

void func() {
	if (!x || x == 1) {
		cout << "2\n";
		return;
	}

	for (ll i = x; ; i++) {
		bool flag = true;
		for (ll j = 2; j * j <= i; j++) {
			if (!(i % j)) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			cout << i << '\n';
			return;
		}
	}
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}