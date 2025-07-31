#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int ret = 0;
	int b = 0;
	for (int i = len - 1; i >= 0; i--, b++) {
		if (str[i] == '0') continue;
		ret += (1 << b);
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}