#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x, y;

void func() {
	if (x.size() < y.size()) swap(x, y);
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	string ret = "";
	int mn = min(x.size(), y.size());
	int mx = max(x.size(), y.size());
	bool f = false;
	for (int i = 0; i < mn; i++) {
		if (x[i] == y[i]) {
			if (f) ret += '1';
			else ret += '0';
			f = (x[i] == '1');
		}
		else {
			if (f) ret += '0';
			else ret += '1';
		}
	}

	for (int i = mn; i < mx; i++) {
		if (x[i] == '1') {
			if (f) ret += '0';
			else ret += '1';
		}
		else {
			if (f) ret += '1';
			else ret += '0';
			f = false;
		}
	}
	if (f) ret += '1';

	while (ret.size() && ret[ret.size() - 1] == '0') {
		ret.pop_back();
	}

	if (ret == "") ret = "0";

	reverse(ret.begin(), ret.end());
	cout << ret << '\n';
}

void input() {
	cin >> x >> y;
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