#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string x, y;

void func() {
	int xInt, yInt;
	string ans;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	xInt = stoi(x);
	yInt = stoi(y);

	ans = to_string(xInt + yInt);
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] == '0') ans.pop_back();
		else break;
	}

	reverse(ans.begin(), ans.end());

	if (ans == "") ans = "0";
	cout << ans << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}