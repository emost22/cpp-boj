#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a, b, c;

void func() {
	ll ret1 = a * a + (b + c) * (b + c);
	ll ret2 = b * b + (a + c) * (a + c);
	ll ret3 = c * c + (a + b) * (a + b);
	cout << min(ret1, min(ret2, ret3)) << '\n';
}

void input() {
	cin >> a >> b >> c;
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