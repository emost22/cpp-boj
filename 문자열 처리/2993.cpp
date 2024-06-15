#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len;

string getFirstWord(string ret, string tmp) {
	if (!ret.size()) return tmp;
	if (ret.compare(tmp) < 0) return ret;
	return tmp;
}

void func() {
	string ret = "";
	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			string tmp = str;
			reverse(tmp.begin(), tmp.begin() + i + 1);
			reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
			reverse(tmp.begin() + j + 1, tmp.end());
			ret = getFirstWord(ret, tmp);
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

	input();
	func();

	return 0;
}