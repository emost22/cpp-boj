#include <iostream>
#include <string>
#define MOD 1000000009
using namespace std;
typedef long long ll;

string str;

void func() {
	int len = str.size();
	char pre = ' ';

	ll ret = 1;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'c') {
			if (str[i] == pre) ret = (ret * 25LL) % MOD;
			else ret = (ret * 26LL) % MOD;
		}
		else {
			if (str[i] == pre) ret = (ret * 9LL) % MOD;
			else ret = (ret * 10LL) % MOD;
		}

		pre = str[i];
	}

	cout << ret << '\n';
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