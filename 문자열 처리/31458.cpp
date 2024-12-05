#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	bool flag = false;
	int idx = 0;
	for (; str[idx] == '!'; idx++) {
		flag = !flag;
	}

	int ret = str[idx++] - '0';
	if (idx < len) ret = 1;
	if (flag) ret = 1 - ret;
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