#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x, y, ans;
int xLen, yLen;

void addRemainNum(string r, int s, int e, int carry) {
	for (int i = s; i < e; i++) {
		int sum = r[i] - '0' + carry;
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		else carry = 0;

		ans += (sum + '0');
	}

	if (carry) ans += '1';
}

void func() {
	ans = "";
	int len = min(xLen, yLen);
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int sum = x[i] - '0' + y[i] - '0' + carry;
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		else carry = 0;

		ans += (sum + '0');
	}

	if (xLen < yLen) {
		addRemainNum(y, xLen, yLen, carry);
	}
	else {
		addRemainNum(x, yLen, xLen, carry);
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

void input() {
	cin >> x >> y;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	xLen = x.size();
	yLen = y.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}