#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int u = 0;
	int d = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'U' || str[i] == 'C') u++;
		else d++;
	}

	string ret = "";
	if (u > (d + 1 >> 1)) {
		ret += 'U';
	}
	if (d) ret += "DP";
	if (ret == "") ret = "C";
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