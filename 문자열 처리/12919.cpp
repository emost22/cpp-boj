#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
int aLen, bLen;

int dfs(int len, string str) {
	if (len < aLen) return 0;
	if (str == a) return 1;

	int ret = 0;
	if (str[len - 1] == 'A') {
		ret = dfs(len - 1, str.substr(0, len - 1));
	}
	
	if (str[0] == 'B') {
		reverse(str.begin(), str.end());
		str.pop_back();
		ret |= dfs(len - 1, str);
	}

	return ret;
}

void func() {
	cout << dfs(bLen, b) << '\n';
}

void input() {
	cin >> a >> b;
	aLen = a.size();
	bLen = b.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}