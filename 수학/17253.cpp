#include <iostream>
#define MAX 39
using namespace std;
typedef long long ll;

ll x;

void func() {
	if (!x) {
		cout << "NO\n";
		return;
	}

	ll m = 1LL;
	for (int i = 0; i < MAX; i++) {
		m *= 3LL;
	}

	for (; m > 0; m /= 3LL) {
		if (x < m) continue;
		x -= m;
	}

	if (!x) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}