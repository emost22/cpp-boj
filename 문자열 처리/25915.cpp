#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string pw = "ILOVEYONSEI";
const int len = pw.size();
string str;
char x;

void func() {
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret += abs(x - pw[i]);
		x = pw[i];
	}

	cout << ret << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}