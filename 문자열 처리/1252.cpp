#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n1, n2;
int len1, len2;

void func() {
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	string ret = "";
	bool carry = false;
	for (int i = 0; i < min(len1, len2); i++) {
		if (n1[i] == n2[i]) {
			if (carry) ret += '1';
			else ret += '0';

			if (n1[i] == '1') carry = true;
			else carry = false;
		}
		else {
			if (carry) ret += '0';
			else ret += '1';
		}
	}

	if (len1 > len2) {
		for (int i = len2; i < len1; i++) {
			if (n1[i] == '1') {
				if (carry) ret += '0';
				else ret += '1';
			}
			else {
				if (carry) {
					ret += '1';
					carry = false;
				}
				else ret += '0';
			}
		}
	}
	else {
		for (int i = len1; i < len2; i++) {
			if (n2[i] == '1') {
				if (carry) ret += '0';
				else ret += '1';
			}
			else {
				if (carry) {
					ret += '1';
					carry = false;
				}
				else ret += '0';
			}
		}
	}

	if (carry) ret += '1';

	while (!ret.empty() && ret[ret.size() - 1] == '0') ret.pop_back();
	if (ret == "") ret = "0";

	reverse(ret.begin(), ret.end());
	cout << ret << '\n';
}

void input() {
	cin >> n1 >> n2;
	len1 = n1.size();
	len2 = n2.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}