#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string a, b;

void func() {
	ll x = 0;
	ll y = 0;
	ll mul = 1LL;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] == '1') {
			x += mul;
		}
		mul *= 2LL;
	}

	mul = 1LL;
	for (int i = b.size() - 1; i >= 0; i--) {
		if (b[i] == '1') {
			y += mul;
		}
		mul *= 2LL;
	}

	ll ret = x * y;
	string ans = "";
	while (ret) {
		if (ret & 1LL) ans += '1';
		else ans += '0';
		ret >>= 1;
	}
	reverse(ans.begin(), ans.end());

	cout << ans << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}