#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int len = str.size();
	int ret = 0;
	int x = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			ret += x;
			x = 0;
		}
		else {
			x = x * 10 + str[i] - '0';
		}
	}
	if (x) ret += x;

	cout << ret << '\n';
}

void input() {
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	getline(cin, str);
	tc = stoi(str);
	while (tc--) {
		input();
		func();
	}

	return 0;
}