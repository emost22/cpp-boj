#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll a, b;

void func() {
	ll ret = a * b;

	string str = "";
	string sa = to_string(a);
	string sb = to_string(b);
	int ia = sa.size() - 1;
	int ib = sb.size() - 1;
	while (ia >= 0 && ib >= 0) {
		str = to_string((sa[ia--] - '0') * (sb[ib--] - '0')) + str;
	}

	while (ia >= 0) {
		str = sa[ia--] + str;
	}

	while (ib >= 0) {
		str = sb[ib--] + str;
	}

	if (stoll(str) == ret) cout << "1\n";
	else cout << "0\n";
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