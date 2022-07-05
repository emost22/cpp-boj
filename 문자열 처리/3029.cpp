#include <iostream>
#include <string>
using namespace std;

string str;
int s, e;

void func() {
	int ans = e - s;
	cout << ans / 36000;
	ans %= 36000;
	cout << ans / 3600 << ':';
	ans %= 3600;
	cout << ans / 600;
	ans %= 600;
	cout << ans / 60 << ':';
	ans %= 60;
	cout << ans / 10 << ans % 10 << '\n';
}

void input() {
	cin >> str;
	s = (str[0] - '0') * 36000 + (str[1] - '0') * 3600 + (str[3] - '0') * 600 + (str[4] - '0') * 60 + (str[6] - '0') * 10 + (str[7] - '0');	
	cin >> str;
	e = (str[0] - '0') * 36000 + (str[1] - '0') * 3600 + (str[3] - '0') * 600 + (str[4] - '0') * 60 + (str[6] - '0') * 10 + (str[7] - '0');

	if (s >= e) {
		e += (24 * 3600);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}