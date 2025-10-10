#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

void func() {
	ll at = a * a;
	ll bt = b * b;
	cout << at / bt + (at % bt != 0) << '\n';
}

void input() {
	cin >> a >> b;
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