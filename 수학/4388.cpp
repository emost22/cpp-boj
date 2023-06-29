#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x, y;

void func() {
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int len1 = x.size();
	int len2 = y.size();
	int carry = 0;
	int ret = 0;
	for (int i = 0; i < min(len1, len2); i++) {
		if (x[i] - '0' + y[i] - '0' + carry > 9) {
			carry = 1;
			ret++;
		}
		else carry = 0;
	}

	if (len1 < len2) {
		for (int i = len1; i < len2; i++) {
			if (y[i] - '0' + carry > 9) {
				carry = 1;
				ret++;
			}
			else carry = 0;
		}
	}
	else {
		for (int i = len2; i < len1; i++) {
			if (x[i] - '0' + carry > 9) {
				carry = 1;
				ret++;
			}
			else carry = 0;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> x >> y;
	if (x == "0" && y == "0") exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (1) {
		input();
		func();
	}

	return 0;
}