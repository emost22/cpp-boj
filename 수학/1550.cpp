#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ans = 0;
	int mul = 1;
	int N = str.size();
	for (int i = N - 1; i >= 0; i--) {
		if ('0' <= str[i] && str[i] <= '9') ans += ((str[i] - '0') * mul);
		else ans += ((str[i] - 'A' + 10) * mul);
		mul <<= 4;
	}

	cout << ans << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}