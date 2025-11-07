#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	string ret = str;
	for (int s = 0; s < len; s++) {
		bool flag = true;
		for (int i = 0; i + s < len; i++) {
			if (str[s + i] == str[len - 1 - i]) continue;
			flag = false;
			break;
		}

		if (flag) {
			for (int i = s - 1; i >= 0; i--) {
				ret.push_back(str[i]);
			}
			break;
		}
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