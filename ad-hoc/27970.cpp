#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

string str;
int len;

void func() {
	int ret = 0;
	int m = 1;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'O') ret = (ret + m) % MOD;
		m = (m << 1) % MOD;
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