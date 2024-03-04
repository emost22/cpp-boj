#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string str;
int len;

void func() {
	ll ret = 0;
	for (int i = 0; i < len; i++) {
		str = str[len - 1] + str.substr(0, len - 1);
		ret += stoll(str);
	}

	cout << ret << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}