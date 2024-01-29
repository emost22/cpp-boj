#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

void func() {
	int ret = 0;
	for (int t = 0; ; t++) {
		if (str == "6174") {
			cout << t << '\n';
			return;
		}

		sort(str.begin(), str.end(), [](char x, char y) {
			return x > y;
		});
		int a = stoi(str);
		reverse(str.begin(), str.end());
		ret = a - stoi(str);
		str = to_string(ret);
		while (str.size() < 4) {
			str += '0';
		}
	}
}

void input() {
	cin >> str;
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